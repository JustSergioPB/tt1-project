#include "VMPCM.h"
#include "PicardChebyshevDemo.h"
#include "auxMethods.h"
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
    // TODO err1 and err2 are infinty 
    double err1 = 0;
    double err2 = 0;
   
    double **t;
    double k[N+2];
    generateIntegerArray(0, N+2, k);
    chebyshevPolynomial(N+2, n, k, tau, &t);

    double v[n];
    generateOnesArray(n, v);
    divideArrayByScalar(n, v, N, v);
    for(int i=1; i < n-1 ; i++){
        v[i] = v[i]*2;
    }

    double TV1[n][m];
    double TV1Aux[N-1][N+2];
    //getRows(0, N-1, N+2, t, TV1Aux);
    //timesMatrixArray(n, m, TV1Aux, v, TV1);

    double TV2[n][m];
    double TV2Aux[N-1][N+2];
    //getRows(2, N+1, m, t, TV2Aux);
    //timesMatrixArray(n, m, TV2Aux, v, TV2);

    double TV[n][m];
    double TVaux[n];
    double TVaux2[n];
    double TV1minusTV2[n][m];
    generateOnesArray(n, TVaux);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            TV1minusTV2[i][j] = TV1[i][j] - TV2[i][j];        
        }
    }
    //generateIngeterArray(1, n, TVaux2);

    for(int i=0; i < n; i++){
        TV[i][m-1] = TV1[i][m-1]/(2*N);    
    }

    double s[n];
    double auxS[n];
    generateIntegerArray(1, n, auxS);
    for(int i = 0; i < n; i++){
        s[i] = 2*pow(-1, auxS[i]+1);
    }

    double Cx[n][m];
    for(int i=0; i < n; i++){
        for(int j=0; j < n; j++){
            Cx[i][j] = t[i][j];
        }
    }
    for(int i =0; i < n; i++){
        Cx[i][1] = Cx[i][1]/2;
    }

    for(int iter = 0; iter < 300 && (errorTolerance < err1 || errorTolerance < err2); iter++){
        iter++;

        double a[n];
        for(int i = 0; i < n; i++){
            a[i] = omega2*tau[i] + omega1;
        }
        
        double **f;
        //twoBodyForceModel(a, &x_guess, mu, f);

        //Numero de columnas de f 
        int sizeF2;
        //Numero de filas de f
        int sizeF1;
    
        if(sizeF2 == 1 || sizeF1 == 1){
            //transpose(n, m, f);
        } 

        int sizeTV1;
        double beta_r[sizeTV1][sizeF2];
        double beta_k[sizeTV1+1][sizeF2]; 
        double **x_new; 

        for(int i=0; i < n; i++){
            for(int j=0; j < sizeF2; j++){
                
            }
        }
        
        /*
        if(){
            transpose(sizeTV1, sizeF2, x_new);
        }*/

        //err2 = err1;
        //err1 = max(absArray());
        //x_guess = x_new;
    }

    freeMatrix(n, t);
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