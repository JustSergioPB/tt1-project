#include "VMPCM.h"
#include "picardChebyshevDemo.h"
#include "algebraFunctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/**
* Generic Function wrapper for the Vectorized Picard Chebyshev Method
*
* @param rows (in) matrixs row number
* @param columns (in) matrixs column number
* @param tau (in) [rows x 1] matrix, transformed time domain vector
* @param x_guess (in/out) [rows x columns] matrix, initial guess of values for the Picar Chebyshev method
* @param omega1 (in) first omega term 
* @param omega2 (in) second omega term
* @param errorTolerance
* @param varargin
*/
void vmpcm(int rows, int columns, double *tau, double ***x_guess, double omega1, double omega2, double errorTolerance, double varargin){
    int N = rows - 1;

    double auxK[rows+1];
    double **tK;
    double v[rows];
    double **TV1;
    double **TV2;
    double **TV;
    double **TV1aux;
    double **TV2aux;
    double **TVaux;
    double aux[N];

    generateIntegerArray(0, rows+1, auxK);
    chebyshevPolynomial(rows+1, rows, auxK, tau, &tK);
    generateOnesArray(rows+1, v);
    for(int i = 0; i < rows; i++){
        if(i > 2 && i < rows-1) v[i] = 2*v[i]/N;
    }
    getRows(rows, 0, N-1, tK, &TV1aux);
    timesArrayMatrix(N, rows, v, TV1aux, &TV1);
    getRows(rows, 2, N+1, tK, &TV2aux);
    timesArrayMatrix(N, rows, v, TV2aux, &TV2);
    generateIntegerArray(1, N, aux);
    multiplyArrayByScalar(N, aux, 2, aux);
    substractMatrixs(N, rows, TV1, TV2, &TVaux);
    dividesArrayMatrix(N, rows, aux, TVaux, &TV);
    for(int j = 0; j < rows; j++){
        TV[N-1][j] = TV1[N-1][j]/2*N;
    }

    double s[N];
    generateIntegerArray(1, N, s);
    for(int i = 0; i < N; i++){
        s[i] = 2*pow(-1, s[i] + 1);
    }

    double **Cx = (double **) calloc(rows, sizeof(double *));
    for(int i = 0; i < rows; i++){
        Cx[i] = (double *) calloc(rows, sizeof(double ));
        for(int j = 0; j < rows; j++){
            Cx[i][j] = (j == 0) ? tK[i][j]/2 : tK[i][j];
        }    
    }

    double **F;
    double **beta_r;
    double **beta_k = (double **) calloc(N+1, sizeof(double *));
    double **x_new;
    double tauTimesOmega2[rows];
    double t[rows];
    double beta_rColumn[N];

    int a[rows];
    int b[rows];
    double err1[rows];
    double err2[rows];
    for(int i =0; i < rows; i++){
        err1[i] = INFINITY;
        err2[i] = INFINITY;
    }

    elemGreaterThanValue(rows, errorTolerance, err1, a);
    elemGreaterThanValue(rows, errorTolerance, err2, b);
    for(int i = 0; i < 300 && (any(rows, a) == 1 || any(rows, b) == 1); i++){

        multiplyArrayByScalar(rows, tau, omega2, tauTimesOmega2);
        addScalarToArray(rows, tauTimesOmega2, omega1, t);
        twoBodyForceModel(rows, columns, t, *x_guess, varargin, &F);
        multiplyMatrixByScalar(rows, columns, omega2, F, &F);

        multiplyMatrixs(N, rows, columns, TV, F, &beta_r);

        beta_k[0] = (double *) calloc(columns, sizeof(double));
        for(int j = 0; j < columns; j++){
            getColumn(N, j, beta_r, beta_rColumn);
            double dot = dotProductArray(N, beta_rColumn, s);
            beta_k[0][j] = isnan(dot) ? NAN : dot + 2* *x_guess[0][j];
        }

        for(int l = 0, k = 1; l < N; l++){
            beta_k[k] = (double *) calloc(columns, sizeof(double));
            for(int j = 0; j < columns; j++){
                beta_k[k][j] = beta_r[l][j];
            }
        }

        multiplyMatrixs(rows, rows, columns, Cx, beta_k, &x_new);

        for(int k = 0; k < rows; k++){
            err2[k] = err1[k];
            err1[k] = fabs(x_new[k][0] - *x_guess[k][0]);
            for(int j = 0; j < columns; j++ ){
                if(err1[k] < fabs(x_new[k][j] - *x_guess[k][j]))
                    err1[k] = fabs(x_new[k][j] - *x_guess[k][j]);

                *x_guess[k][j] = x_new[k][j];
            }
        }

        elemGreaterThanValue(rows, errorTolerance, err1, a);
        elemGreaterThanValue(rows, errorTolerance, err2, b);
    }

    freeMatrix(rows+1, tK);
    freeMatrix(N, TV1);
    freeMatrix(N, TV2);
    freeMatrix(N, TV);
    freeMatrix(N, TV1aux);
    freeMatrix(N, TV2aux);
    freeMatrix(N, TVaux);
    freeMatrix(rows, Cx);
    freeMatrix(N, beta_r);
    freeMatrix(N+1, beta_k);
    freeMatrix(N+1, x_new);
} 

/**
* Calculates Chebyshev polynomial corresponding to degree K from tau
* 
* @param sizeK (in) k's size
* @param sizeTau (in) tau's size
* @param k (in) array 
* @param tau (in) array
* @param tK (out) matrix 
*/
void chebyshevPolynomial(int sizeK, int sizeTau, double *k, double *tau, double ***tK)
{
    double **m;

    m = (double **) calloc(sizeK, sizeof(double *));

    for(int i = 0; i < sizeK; i++){
        m[i] = (double *) calloc(sizeTau, sizeof(double ));
        for(int j = 0; j < sizeTau; j++){
            m[i][j] = cos(k[i]*acos(tau[j]));
        }
    }

    *tK = m;
}