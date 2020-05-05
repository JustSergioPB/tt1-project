#include "VMPCM.h"
#include "picardChebyshevDemo.h"
#include "algebraFunctions.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#ifdef INFINITY
/* INFINITY is supported */
#endif

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
*/
void vmpcm(int rows, int columns, double *tau, double ***x_guess, double omega1, double omega2, double errorTolerance){
    int N = rows - 1;

    double auxK[rows+1];
    double **tK = (double **) calloc(rows+1, sizeof(double *));
    generateIntegerArray(0, rows+1, auxK);
    chebyshevPolynomial(rows+1, rows, auxK, tau, &tK);

    double v[rows];
    generateOnesArray(rows+1, v);
    for(int i = 0; i < rows; i++){
        if(i > 2 && i < rows-1){
            v[i] = 2*v[i]/N;
        }
    }

    double **TV1;
    double **TV2;
    double **TV;
    double **TV1aux = (double **) calloc(N, sizeof(double *));
    double **TV2aux = (double **) calloc(N, sizeof(double *));
    double **TVaux;
    double aux[N];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < rows; j++){
            TV1aux[i][j] = tK[i][j];
        }
    }

    for(int i = 1, k = 0; i < rows+1; i++){
        for(int j = 0; j < rows; j++){
            TV2aux[k][j] = tK[i][j];
        }
        k++;
    }

    timesArrayMatrix(N, rows, v, TV1aux, &TV1);
    timesArrayMatrix(N, rows, v, TV2aux, &TV2);
    generateIntegerArray(1, N, aux);
    for(int i = 0; i < N; i++){
        aux[i] = aux[i]*2;
    }
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
        for(int j = 0; j < rows; j++){
            if(j == 0){
                Cx[i][j] = tK[i][j]/2;
            } else {
                Cx[i][j] = tK[i][j];
            }
        }    
    }

    //TODO change from double to infinity
    double err1[rows];
    double err2[rows];
    for(int i =0; i < rows; i++){
        err1[i] = INFINITY;
        err2[i] = INFINITY;
    }
    double mu = 398600.4415;
    //TODO check size and freeMatrix later
    double **f;
    double **beta_r;
    double **beta_k;
    double **x_new;
    double tauTimesOmega2[rows];
    double t[rows];
    // Check length once multiplyArrayByMatrix is finished 
    double SmulBeta_r[columns];

    int a[rows];
    int b[rows];
    elemGreaterThanValue(rows, errorTolerance, err1, a);
    elemGreaterThanValue(rows, errorTolerance, err2, b);
    for(int i = 0; i < 300 && (any(rows, a) == 1 || any(rows, b) == 1); i++){

        multiplyArrayByScalar(rows, tau, omega2, tauTimesOmega2);
        addScalarToArray(rows, tauTimesOmega2, omega1, t);
        twoBodyForceModel(rows, columns, t, *x_guess, mu, &f);

        for(int k = 0; k < rows; k++){
            for(int j = 0; j < columns; j++){
                f[k][j] = f[k][j]*omega2;
            }
        }

        if(rows == 1 || columns == 1){
            int aux1;
            transpose(rows, columns, f, &f);
            aux1 = rows;
            rows = columns;
            columns = aux1;
        }

        multiplyMatrixs(N, rows, rows, columns, TV, f, &beta_r);
        //TODO check how operations are done for beta_k 
        multiplyArrayByMatrix(N, N, columns, s, beta_r, SmulBeta_r);
        multiplyMatrixs(rows, rows, rows, columns, Cx, beta_k, &x_new);

        //TODO Check if this condition is necesary
        //if()

        for(int k = 0; k < rows; k++){
            err2[k] = err1[k];
        }

        for(int k = 0; k < rows; k++){
            err1[k] = fabs(x_new[k][0] - *x_guess[k][0]);
            for(int j = 0; j < columns; j++ ){
                if(err1[k] < fabs(x_new[k][j] - *x_guess[k][j]))
                    err1[k] = fabs(x_new[k][j] - *x_guess[k][j]);
            }
        }

        for(int k = 0; k < rows; k++){
            for(int j = 0; j < columns; j++ ){
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
void chebyshevPolynomial(int sizeK, double sizeTau, double *k, double *tau, double ***tK)
{
    double **m;

    m = (double **) calloc(sizeK, sizeof(double *));

    for(int i = 0; i < sizeK; i++){
        for(int j = 0; j < sizeTau; j++){
            m[i][j] = cos(k[i]*acos(tau[j]));
        }
    }

    *tK = m;
}