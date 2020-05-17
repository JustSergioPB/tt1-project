#include "algebraFunctions.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

/**
 * Console print for a matrix
 *
 * @param mat
 * @param filas
 * @param colum
 */
void printMatriz(double **mat, int filas, int colum)
{
    int i, j;

    for(i = 0; i < filas; i++){
        for(j = 0; j < colum; j++){
            printf("%5.15lf ", mat[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

/**
 * Console print for an array
 * @param a
 * @param length
 */
void printArray(double *a, int length){
    for(int i = 0; i < length; i++){
        printf("%5.15lf ", a[i]);
        printf("\n");
    }

    printf("\n");
}

/**
 * Frees memory resources occupied by a matrix
 *
 * @param rows
 * @param matrix
 */
void freeMatrix(int rows, double **matrix)
{
    int i;

    for(i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

/**
 * Returns a specific column from a matrix
 *
 * @param rows
 * @param columnNumber
 * @param matrix
 * @param column
 */
void getColumn(int rows, int columnNumber, double **matrix, double *column){
    for(int i = 0; i < rows; i++){
        column[i] = matrix[i][columnNumber];
    }
}

/**
 * Returns a specific row from a matrix
 *
 * @param columns
 * @param rowNumber
 * @param matrix
 * @param row
 */
void getRow(int columns, int rowNumber, double **matrix, double *row){
    for(int j = 0; j < columns; j++){
        row[j] = matrix[rowNumber][j];
    }
}

/**
 * Returns an array where result[i] = matrix[0][j] + ... + matrix[columns][j]
 *
 * @param rows
 * @param columns
 * @param matrix
 * @param result
 */
void sumMatrixRows(int rows, int columns, double **matrix, double *result){
    for(int i = 0; i < columns; i++){
        result[i] = 0;
        for(int j = 0; j < rows; j++){
            result[i] += matrix[j][i];
        }   
    }
}

/**
 * Returns number of true values in an array
 *
 * @param length
 * @param a
 * @return
 */
int truesInArray(int length, int *a){
    int num = 0;

    for(int i=0; i < length; i++){
        if(a[i] == 1)
            num++;
    }
    return num;
}

/**
 * Returns a matrix where result[i][j] = pow(matrix[i][j], coef)
 *
 * @param rows
 * @param columns
 * @param coef
 * @param matrix
 * @param result
 */
void matrixPow(int rows, int columns, int coef, double **matrix, double ***result){
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = pow(matrix[i][j], coef);
        }
    }

    *result = m;
}

/**
 *
 * @param rowsMatrixA
 * @param colsMatrixA
 * @param colsMatrixB
 * @param matrixA
 * @param matrixB
 * @param result
 */
void multiplyMatrixs(int rowsMatrixA, int colsMatrixA, int colsMatrixB, double **matrixA, double **matrixB, double ***result){
    double **m;

    m = (double **) calloc(rowsMatrixA, sizeof(double *));

    double rowA[colsMatrixA];
    double columnB[colsMatrixA];

    for(int i = 0; i < rowsMatrixA; i++) {
        m[i] = (double *) calloc(colsMatrixB, sizeof(double ));
        for(int j = 0; j < colsMatrixB; j++){
            getRow(colsMatrixA, i, matrixA, rowA);
            getColumn(colsMatrixA, j, matrixB, columnB);
            m[i][j] = dotProductArray(colsMatrixA, rowA, columnB);
        }
    }

    *result = m;
}

/**
 *
 * @param length
 * @param value
 * @param a
 * @param result
 */
void elemGreaterThanValue(int length, double value, double *a, int *result){
    for(int i=0; i < length; i++){
        if(a[i] > value){
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
}

/**
 *
 * @param length
 * @param value
 * @param a
 * @param result
 */
void elemLowerThanValue(int length, double value, double *a, int *result){
    for(int i=0; i < length; i++){
        if(a[i] < value){
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
}

/**
 *
 * @param length
 * @param a
 * @param result
 */
void absArray(int length, double *a, double *result){
    for(int i=0; i < length; i++){
        result[i] = fabs(a[i]);
    }
}

/**
 *
 * @param num
 * @return
 */
int sign(double num){

    int result = 0;

    if(num > 0){
        result = 1;
    } else if(num < 0) {
        result = -1;
    }

    return result;
}

/**
 *
 * @param rows
 * @param columns
 * @param matrixA
 * @param matrixB
 * @param result
 */
void dotProductMatrix(int rows, int columns, double **matrixA, double **matrixB, double *result){

    double matrixAColumn[rows];
    double matrixBColumn[rows];
    for(int j = 0; j < columns; j++){
        getColumn(rows, j, matrixA, matrixAColumn);
        getColumn(rows, j, matrixB, matrixBColumn);
        result[j] = dotProductArray(rows, matrixAColumn, matrixBColumn);
    }
}

/**
 *
 * @param length
 * @param a
 * @param b
 * @return
 */
double dotProductArray(int length, double *a, double *b){
    double dotProduct = 0.0;

    for(int i = 0; i < length; i++){
        dotProduct += a[i]*b[i];
    }

    return dotProduct;
}

/**
 *
 * @param rows
 * @param columns
 * @param a
 * @param matrix
 * @param result
 */
void timesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result){

    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = matrix[i][j]*a[j];
        }
    }

    *result = m;
}

/**
 *
 * @param rows
 * @param columns
 * @param a
 * @param matrix
 * @param result
 */
void dividesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result){

    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = matrix[i][j]*(1/a[i]);
        }
    }

    *result = m;
}

/**
 *
 * @param rows
 * @param columns
 * @param a
 * @param b
 * @param result
 */
void addMatrixs(int rows, int columns, double **a, double **b, double ***result){
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = a[i][j]+b[i][j];
        }
    }

    *result = m;
}

/**
 *
 * @param rows
 * @param columns
 * @param a
 * @param b
 * @param result
 */
void substractMatrixs(int rows, int columns, double **a, double **b, double ***result){
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = a[i][j]-b[i][j];
        }
    }

    *result = m;
}

/**
 *
 * @param length
 * @param a
 * @return
 */
int any(int length, int *a){
    int any = 0;

    for(int i=0; i < length; i++){
        if(a[i] == 1){
            any = 1;
            break;
        }
    }

    return any;
}

/**
 *
 * @param a
 * @param b
 * @param cross
 */
void crossProductArray(double *a, double *b, double *cross){
    cross[0] = a[1]*b[2] - a[2]*b[1];
    cross[1] = a[2]*b[0] - a[0]*b[2];
    cross[2] = a[0]*b[1] - a[1]*b[0];
}

/**
 *
 * @param rows
 * @param columns
 * @param matrixA
 * @param matrixB
 * @param result
 */
void crossProductMatrix(int rows, int columns, double **matrixA, double **matrixB, double ***result){
    double crossColumn[rows];
    double matrixAColumn[rows];
    double matrixBColumn[rows];
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++)
        m[i] = (double *) calloc(columns, sizeof(double));

    for(int j = 0; j < columns; j++){
        getColumn(rows, j, matrixA, matrixAColumn);
        getColumn(rows, j, matrixB, matrixBColumn);
        crossProductArray(matrixAColumn, matrixBColumn, crossColumn);
        for(int i = 0; i < rows; i++){
            m[i][j] = crossColumn[i];
        }
    }

    *result = m;
}

/**
 *
 * @param rows
 * @param columns
 * @param logicArray
 * @param matrixA
 * @param resultColumns
 * @param result
 */
void getTrueColumns(int rows, int columns, int *logicArray, double **matrixA, int resultColumns, double ***result){
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(resultColumns, sizeof(double));
        for(int j = 0, k = 0; j < columns; j++){
            if(logicArray[j] == 1){
                m[i][k] = matrixA[i][j];
                k++;
            }
        }
    }

    *result = m;
}

/**
 * Returns a matrix containing the specified rows from a row number until a row number
 *
 * @param columns
 * @param from
 * @param until
 * @param matrix
 * @param result
 */
void getRows(int columns, int from, int until, double **matrix, double ***result){
    double **m;

    int resultRows = until - from + 1;

    m = (double **) calloc(resultRows, sizeof(double *));

    for(int i = 0, k = from; k <= until; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = matrix[k][j];
        }
        k++;
    }

    *result = m;
}

/**
 *
 * @param rows
 * @param columns
 * @param scalar
 * @param matrix
 * @param result
 */
void multiplyMatrixByScalar(int rows, int columns, double scalar, double **matrix, double ***result){
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            m[i][j] = matrix[i][j]*scalar;
        }
    }

    *result = m;
}

/**
 *
 * @param length
 * @param a
 * @param scalar
 * @param result
 */
void multiplyArrayByScalar(int length, double *a, double scalar, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i]*scalar;
}

/**
 *
 * @param length
 * @param a
 * @param scalar
 * @param result
 */
void divideArrayByScalar(int length, double *a, double scalar, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i]/scalar;
}

/**
 *
 * @param from
 * @param length
 * @param a
 */
void generateIntegerArray(int from, int length, double *a){
    for(int i = 0; i < length; i++){
        a[i] = from;
        from ++;
    }
}

/**
 *
 * @param length
 * @param a
 */
void generateOnesArray(int length, double *a){
    for(int i = 0; i < length; i++)
        a[i] = 1;
}