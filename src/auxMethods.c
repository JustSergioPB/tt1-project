#include "auxMethods.h"
#include <stdlib.h>
#include <math.h>
/*
void createMatrix(int rows, int columns, double ***mat)
{
    double **m;
    int i;

    m = (double **) calloc(filas, sizeof(double *));
    for(i = 0; i < filas; i++)
         m[i] = (double *) calloc(colum, sizeof(double));
 
    *mat = m;
}*/


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
        for(int j = 0; j < columns; i++){
            m[i][j] = pow(matrix[i][j], coef); 
        }   
    }

    *result = m;
}

void arrayPow(int length, int coef, double *a, double *result){
    for(int i = 0; i < length; i++){
        result[i] = pow(a[i], 2);   
    }
}

void compressToOneDim(int rows, int columns, double **matrix, double *result){
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; i++){
            result[i] += matrix[i][j]; 
        }   
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

void elemLowerOrEqualThanValue(int length, double value, double *a, int *result){
    for(int i=0; i < length; i++){
        if(a[i] <= value){
            result[i] = 1;
        } else {
            result[i] = 0;
        }
    }
}

void absArray(int length, double *a, double *result){
    for(int i=0; i < length; i++){
        result[i] = abs(a[i]);
    }
}

void multiplyArrays(int length, double *a, double *b, double *result){
    for(int i=0; i < length; i++){
        result[i] = a[i]*b[i];
    }
}

int sign(double num){

    int result;

    if(num > 0){
        result = 1;
    } else if(num < 0) {
        result = -1;
    } else if(num == 0) {
        result= 0;
    }

    return result;
}


double dotProduct(int rows, int columns, double **matrixA, double **matrixB){
    double dotProduct = 0.0;

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            dotProduct += matrixA[i][j]*matrixB[i][j];
        }
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
        for(int j = 0; j < columns; j++){
            m[i][j] = matrix[i][j]*a[i];
        }
    }

    *result = m;
}

void dividesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result){

    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            m[i][j] = matrix[i][j]/a[i];
        }
    }

    *result = m;
}

void addMatrixs(int rows, int columns, double **a, double **b, double ***result){
    double **m;

    m = (double **) calloc(rows, sizeof(double *));

    for(int i = 0; i < rows; i++){
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

void crossProduct(int length, double *a, double *b, double *cross){
    cross[0] = a[1]*b[2] - a[2]*b[1];
    cross[1] = a[2]*b[0] - a[0]*b[2];
    cross[2] = a[0]*b[1] - a[1]*b[0];
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

void addArrays(int length, double *a, double *b, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i]+b[i];
}

void addScalarToArray(int length, double *a, double scalar, double *result){
    for(int i=0; i < length; i++)
        result[i] = a[i] + scalar;
}

void transpose(int rows, int columns, double **source, double ***transposed){
    double **m;

    m = (double **) calloc(columns, sizeof(double *));

    for(int i=0; i < columns; i++){
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