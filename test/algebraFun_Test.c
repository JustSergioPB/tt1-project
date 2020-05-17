#include "algebraFun_Test.h"
#include "VMCPMModule/algebraFunctions.h"
#include <assert.h>
#include <stdlib.h>

int matrixPow_Test(){
    double **matrix = calloc(3, sizeof(double *));
    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double));
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
        matrix[i] = calloc(4, sizeof(double));
        for(int j = 0; j < 4; j++){
            matrix[i][j] = 1;
        }
    }

    double result[4];

    sumMatrixRows(3, 4, matrix, result);

    double expected[4] = {3,3,3,3};

    for(int i = 0; i < 3; i++){
        assert(result[i] == expected[i]);
    }

    freeMatrix(3, matrix);

    return 0;
}

int elemGreaterThanValue_Test(){
    double alpha[3] = {1, 3, -3};
    int result[3];

    elemGreaterThanValue(3, 2, alpha, result);

    int expected[3] = {0,1,0};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == result[i]);
    }

    return 0;
}

int elemLowerThanValue_Test(){
    double alpha[3] = {1, 2, -3};
    int result[3];

    elemLowerThanValue(3, 2, alpha, result);

    int expected[3] = {1,0,1};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == result[i]);
    }

    return 0;
}

int absArray_Test(){
    double alpha[3] = {1, 2, -3};
    double result[3];

    absArray(3, alpha, result);

    int expected[3] = {1,2,3};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == result[i]);
    }

    return 0;
}

int any_Test(){
    int arr[3] = {0,1,0};

    int result = any(3, arr);

    assert(result == 1);

    return 0;
}

int truesInArray_Test(){
    int arr[3] = {0,1,0};

    int result = truesInArray(3, arr);

    assert(result == 1);

    return 0;
}

int crossProductArray_Test() {
    double id[3] = {1,0,0};
    double d[3] = {1,2,3};
    double result[3];

    crossProductArray(id, d, result);

    double expected[3] = {0,-3,2};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == result[i]);
    }

    return 0;
}

int getColumn_Test(){
    double **r0 = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        r0[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            if(i == j){
                r0[i][j] = 1;
            } else{
                r0[i][j] = 0;
            }
        }
    }

    double result[3];

    getColumn(3,0,r0, result);

    double expected[3] = {1,0,0};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == result[i]);
    }

    freeMatrix(3,r0);
    return 0;
}

int crossProductMatrix_Test() {
    double **matrix = calloc(3, sizeof(double *));
    double **matrixB = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(4, sizeof(double));
        matrixB[i] = calloc(4, sizeof(double));

        for(int j = 0; j < 4; j++){
            matrixB[i][j] = j+1;

            if(i == j || j == 3){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    double **result;

    crossProductMatrix(3,4, matrix, matrixB ,&result);

    double expected[3][4] = {
            {0, 2, -3, 0},
            {-1, 0, 3, 0},
            {1, -2, 0, 0}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int getTrueColumns_Test() {
    double **matrix = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double));

        for(int j = 0; j < 3; j++){
            if(i == j){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    int idx[3] = {1,0,1};
    double **result;

    getTrueColumns(3,3, idx, matrix, 2, &result);

    double expected[3][2] = {
            {1, 0},
            {0, 0},
            {0, 1}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int matrixDotProduct_Test(){
    double a[3] = {1,1,1};
    double b[3] = {1,2,3};

    assert(6 == dotProductArray(3,a,b));

    return 0;
}

int arrayDotProduct_Test(){
    double **r0 = calloc(3, sizeof(double *));
    double **v0 = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        r0[i] = calloc(3, sizeof(double));
        v0[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            v0[i][j] = j+1;
            if(i == j){
                r0[i][j] = 1;
            } else{
                r0[i][j] = 0;
            }
        }
    }

    double result[3];

    dotProductMatrix(3,3, r0, v0, result);

    double expected[3] = {1,2,3};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == result[i]);
    }

    return 0;
}

int generateIntegerArray_Test(){
    double v[3];

    generateIntegerArray(0,3,v);

    double expected[3] = {0,1,2};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == v[i]);
    }

    return 0;
}

int generateOnesArray_Test(){
    double v[3];

    generateOnesArray(3,v);

    double expected[3] = {1,1,1};

    for(int i = 0; i < 3; i++){
        assert(expected[i] == v[i]);
    }
    return 0;
}

int timesArrayMatrix_Test(){
    double **matrix = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(4, sizeof(double));
        for(int j = 0; j < 4; j++){
            if(i == j || j == 3){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    double arr[4] = {1,2,3,4};
    double **result;

    timesArrayMatrix(3,4,arr,matrix, &result);

    double expected[3][4] = {
            {1,0,0,4},
            {0,2,0,4},
            {0,0,3,4}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int substractMatrixs_Test(){
    double **r0 = calloc(3, sizeof(double *));
    double **v0 = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        r0[i] = calloc(3, sizeof(double));
        v0[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            if(i == j){
                r0[i][j] = 1;
                v0[i][j] = 1;
            } else{
                r0[i][j] = 0;
                v0[i][j] = 0;
            }
        }
    }
    double **result;

    substractMatrixs(3,3,r0,v0,&result);

    double expected[3][3] = {
            {0,0,0},
            {0,0,0},
            {0,0,0}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int dividesArrayMatrix_Test(){
    double **matrix = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(4, sizeof(double));
        for(int j = 0; j < 4; j++){
            if(i == j || j == 3){
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    double arr[4] = {1,2,3,4};
    double **result;

    dividesArrayMatrix(3,4,arr,matrix, &result);

    double expected[3][4] = {
            {1.0,0.0,0.0,   0.25},
            {0.0,0.5,0.0,   0.25},
            {0.0,0.0,0.3333,0.25}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int getRows_Test(){
    double **matrix = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    double **result;

    getRows(3, 0,1, matrix, &result);

    double expected[2][3] = {
            {1, 0, 0},
            {0, 1, 0}
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int multiplyMatrixByScalar_Test(){
    double **matrix = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    double **result;

    multiplyMatrixByScalar(3,3,2 ,matrix, &result);

    double expected[3][3] = {
            {2, 0, 0},
            {0, 2, 0},
            {0, 0, 2}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}

int getRow_Test(){
    double **matrix = calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            matrix[i][j] = (i == 0) ? j + 1: 1;
        }
    }

    double row[3];

    getRow(3, 0, matrix, row);

    double expected[3] = {1,2,3};

    for(int i =0; i < 3; i++){
        assert(expected[i] == row[i]);
    }

    return 0;
}

int multiplyMatrixs_Test(){
    double **matrix = calloc(3, sizeof(double *));
    double **matrixB = calloc(2, sizeof(double *));
    double **result;

    for(int i = 0; i < 2; i++){
        matrixB[i] = calloc(3, sizeof(double));
        for(int j = 0; j < 3; j++){
            matrixB[i][j] = j+1;
        }
    }

    for(int i = 0; i < 3; i++){
        matrix[i] = calloc(2, sizeof(double));
        for(int j = 0; j < 2; j++){
            matrix[i][j] = (i == j) ? 1 : 0;
        }
    }

    multiplyMatrixs(2,3,2, matrixB, matrix, &result);

    double expected[2][2] = {
            {1,2},
            {1,2}
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++) {
            assert(expected[i][j] == result[i][j]);
        }
    }

    return 0;
}



