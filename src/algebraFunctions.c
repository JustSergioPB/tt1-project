#include "algebraFunctions.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

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

void printArray(double *a, int length){
    for(int i = 0; i < length; i++){
        printf("%5.15lf ", a[i]);
        printf("\n");
    }

    printf("\n");
}


void freeMatrix(int rows, double **matrix)
{
    int i;

    for(i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}

void getColumn(int rows, int columnNumber, double **matrix, double *column){
    for(int i = 0; i < rows; i++){
        column[i] = matrix[i][columnNumber];
    }
}

void getRow(int columns, int rowNumber, double **matrix, double *row){
    for(int j = 0; j < columns; j++){
        row[j] = matrix[rowNumber][j];
    }
}

void sumMatrixRows(int rows, int columns, double **matrix, double *result){
    for(int i = 0; i < columns; i++){
        result[i] = 0;
        for(int j = 0; j < rows; j++){
            result[i] += matrix[j][i];
        }   
    }
}

int truesInArray(int length, int *a){
    int num = 0;

    for(int i=0; i < length; i++){
        if(a[i] == 1)
            num++;
    }
    return num;
}

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

void arrayPow(int length, int coef, double *a, double *result){
    for(int i = 0; i < length; i++){
        result[i] = pow(a[i], coef);
    }
}

void elemGreaterThanValue(int length, double value, double *a, int *result){
    for(int i=0; i < length; i++){
        if(a[i] > value){
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
}

void elemLowerThanValue(int length, double value, double *a, int *result){
    for(int i=0; i < length; i++){
        if(a[i] < value){
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
}

void absArray(int length, double *a, double *result){
    for(int i=0; i < length; i++){
        result[i] = fabs(a[i]);
    }
}

void multiplyArrays(int length, double *a, double *b, double *result){
    for(int i=0; i < length; i++){
        result[i] = a[i]*b[i];
    }
}

int sign(double num){

    int result = 0;

    if(num > 0){
        result = 1;
    } else if(num < 0) {
        result = -1;
    }

    return result;
}


void dotProductMatrix(int rows, int columns, double **matrixA, double **matrixB, double *result){

    double matrixAColumn[rows];
    double matrixBColumn[rows];
    for(int j = 0; j < columns; j++){
        getColumn(rows, j, matrixA, matrixAColumn);
        getColumn(rows, j, matrixB, matrixBColumn);
        result[j] = dotProductArray(rows, matrixAColumn, matrixBColumn);
    }
}

double dotProductArray(int length, double *a, double *b){
    double dotProduct = 0.0;

    for(int i = 0; i < length; i++){
        dotProduct += a[i]*b[i];
    }

    return dotProduct;
}

void timesArrayArray(int lengthA, int lenghtB, double *a, double *b, double ***result){

    double **m;

    m = (double **) calloc(lengthA, sizeof(double *));

    for(int i = 0; i < lengthA; i++){
        for(int j = 0; j < lenghtB; j++){
            m[i][j] = a[i]*b[j];
        }
    }

    *result = m;
}

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

void crossProductArray(double *a, double *b, double *cross){
    cross[0] = a[1]*b[2] - a[2]*b[1];
    cross[1] = a[2]*b[0] - a[0]*b[2];
    cross[2] = a[0]*b[1] - a[1]*b[0];
}

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

double sumArrayElements(int length, double *a){
    double sum = 0;
    
    for(int i =0; i < length; i++)
        sum += a[i];

    return sum;
}

void multiplyArrayByScalar(int length, double *a, double scalar, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i]*scalar;
}

void divideArrayByScalar(int length, double *a, double scalar, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i]/scalar;
}

void addScalarToArray(int length, double *a, double scalar, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i] + scalar;
}

void transpose(int rows, int columns, double **source, double ***transposed){
    double **m;

    m = (double **) calloc(columns, sizeof(double *));

    for(int i=0; i < columns; i++){
        m[i] = (double *) calloc(columns, sizeof(double));
        for(int j=0; j < rows; j++){
            m[j][i] = source[i][j];
        }
    }

    *transposed = m;
}

void generateIntegerArray(int from, int length, double *a){
    for(int i = 0; i < length; i++){
        a[i] = from;
        from ++;
    }
}

void generateOnesArray(int length, double *a){
    for(int i = 0; i < length; i++)
        a[i] = 1;
}