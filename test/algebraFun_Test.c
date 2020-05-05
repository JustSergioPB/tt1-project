#include "algebraFun_Test.h"
#include "algebraFunctions.h"
#include <assert.h>
#include <stdlib.h>

int matrixPow_Test(){
    double **matrix = calloc(3, sizeof(double *));
    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double *));
        for(int j = 0; j < 3; j++){
            matrix[i][j] = 2;
        }
    }

    double **result;

    matrixPow(3, 3, 2, matrix, &result);

    double expected[3][3] = {
            {4,4,4},
            {4,4,4},
            {4,4,4}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            assert(result[i][j] == expected[i][j]);
        }
    }

    freeMatrix(3, result);

    return 0;
}

int sumMatrixRows_Test(){
    double **matrix = calloc(3, sizeof(double *));
    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double *));
        for(int j = 0; j < 3; j++){
            matrix[i][j] = 1;
        }
    }

    double result[3];

    sumMatrixRows(3, 3, matrix, result);

    double expected[3] = {3,3,3};

    for(int i = 0; i < 3; i++){
        assert(result[i] == expected[i]);
    }

    freeMatrix(3, matrix);

    return 0;
}

