#include "VMPCM.h"
#include "PicardChebyshevDemo.h"
#include <stdlib.h>

/**
* Generic Function wrapper for the Vectorized Picard Chebyshev Method
*
* @param n matrixs row number
* @param m matrixs column number
* @param tau [n x 1] matrix, transformed time domain vector
* @param x_guess [n x m] matrix, initial guess of values for the Picar Chebyshev method
* @param omega1 first omega term 
* @param omega2 second omega term
* @param errorTolerance 
*/
double ** vmpcm(int n, int m, double tau[n][1], double x_guess[n][m], double omega1, double omega2, double errTol){

    double ** returned = calloc(n, sizeof(double *));

    return returned;
} 

/**
* Calculates Chebyshev polynomial corresponding to degree K from tau
* 
* @param k
* @param tau 
*/
double * chebyshevPolynomial(double k[], double tau[])
{
    double *tK = malloc(1);
    return tK;
}