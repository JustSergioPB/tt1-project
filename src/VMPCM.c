#include "VMPCM.h"
#include "PicardChebyshevDemo.h"
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
* @param n (in) matrixs row number
* @param m (in) matrixs column number
* @param tau (in) [n x 1] matrix, transformed time domain vector
* @param x_guess (in/out) [n x m] matrix, initial guess of values for the Picar Chebyshev method
* @param omega1 (in) first omega term 
* @param omega2 (in) second omega term
* @param errorTolerance 
*/
void vmpcm(int n, int m, double *tau, double ***x_guess, double omega1, double omega2, double errorTolerance){
    int N = n - 1;

    double k[n+1];
    double **tK = (double **) calloc(n+1, sizeof(double *));
    generateIntegerArray(0, n+1, k);
    chebyshevPolynomial(n+1, n, k, tau, &tK);

    double v[n];
    generateOnesArray(n+1, v);
    for(int i = 0; i < n; i++){
        if(i > 2 && i < n-1){
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
        for(int j = 0; j < n; j++){
            TV1aux[i][j] = tK[i][j];
        }
    }

    int l = 0;
    for(int i = 1; i < n+1; i++){
        for(int j = 0; j < n; j++){
            TV2aux[l][j] = tK[i][j];
        }
        l++;
    }

    timesArrayMatrix(N, n, v, TV1aux, &TV1);
    timesArrayMatrix(N, n, v, TV2aux, &TV2);
    generateIntegerArray(1, N, aux);
    for(int i = 0; i < N; i++){
        aux[i] = aux[i]*2;
    }
    substractMatrixs(N, n, TV1, TV2, &TVaux);
    dividesArrayMatrix(N, n, aux, TVaux, &TV);
    for(int j = 0; j < n; j++){
        TV[N-1][j] = TV1[N-1][j]/2*N;
    }

    double s[N];
    generateIntegerArray(1, N, s);
    for(int i = 0; i < N; i++){
        s[i] = 2*pow(-1, s[i] + 1);
    }

    //TODO check size and freeMatrix later
    double **Cx = (double **) calloc(n, sizeof(double *));
    //TODO check how values are asigned and stop condition
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j = 0){
                Cx[i][j] = tK[i][j]/2;
            } else {
                Cx[i][j] = tK[i][j];
            }
        }    
    }

    //TODO change from double to infinity
    double err1[n];
    double err2[n];
    double mu = 398600.4415;
    //TODO check size and freeMatrix later
    double **f;
    double **beta_r;
    double **beta_k;
    double **x_new;
    double tauTimesOmega2[n];
    double t[n];
    // Check length once multiplyArrayByMatrix is finished 
    double SmulBeta_r[m];
    double maxValues[n];

    int a[n];
    int b[n];
    elemGreaterThanValue(n, errorTolerance, err1, a);
    elemGreaterThanValue(n, errorTolerance, err2, b);
    for(int i = 0; i < 300 && (any(n, a) == 1 || any(n, b) == 1); i++){

        multiplyArrayByScalar(n, tau, omega2, tauTimesOmega2);
        addScalarToArray(n, tauTimesOmega2, omega1, t);
        twoBodyForceModel(n, m, t, *x_guess, mu, &f);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                f[i][j] = f[i][j]*omega2; 
            }
        }

        if(n == 1 || m == 1){
            int aux;
            transpose(n, m, f, &f);
            aux = n;
            n = m;
            m = aux;
        }

        multiplyMatrixs(N, n, n, m, TV, f, &beta_r);
        //TODO check how operations are done for beta_k 
        multiplyArrayByMatrix(N, N, m, s, beta_r, SmulBeta_r);
        multiplyMatrixs(n, n, n, m, Cx, beta_k, &x_new);

        //TODO Check if this condition is necesary
        //if()

        for(int i = 0; i < n; i++){
            err2[i] = err1[i];
        }

        for(int i = 0; i < n; i++){
            err1[i] = abs(x_new[i][0] - *x_guess[i][0]);
            for(int j = 0; j < m; j++ ){
                if(err1[i] < abs(x_new[i][j] - *x_guess[i][j]))
                    err1[i] = abs(x_new[i][j] - *x_guess[i][j]);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++ ){
                *x_guess[i][j] = x_new[i][j];
            }
        }

        elemGreaterThanValue(n, errorTolerance, err1, a);
        elemGreaterThanValue(n, errorTolerance, err2, b);
    }

    freeMatrix(n+1, tK);
    freeMatrix(N, TV1);
    freeMatrix(N, TV2);
    freeMatrix(N, TV);
    freeMatrix(N, TV1aux);
    freeMatrix(N, TV2aux);
    freeMatrix(N, TVaux);
    freeMatrix(n, Cx);
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