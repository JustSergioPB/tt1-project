#include "keplerUniversal.h"
#include <stdlib.h>

/**
* Most effecient way to propagate any type of two body orbit using kepler's equations.
*
* @param n matrixs column's number
* @param r0 [3 x n] matrix, position Vector in ECI coordinate frame of reference
* @param v0 [3 x n] matrix, velocity Vector in ECI coordinate frame of reference
* @param timeVector [1 x n] matrix, time vector in seconds
* @param mu Gravitional Constant, if not specified value is Earth's mu constant
*
*/
double ** keplerUniversal(int n, double r0[3][n], double v0[3][n], double timeVector[1][n], double mu){
    
    double ** returned = calloc(n, sizeof(double *));

    return returned;
}

/**
* Returns matrix 
*
* @param n size of psi
* @param psi 
*/
double ** c2c3(int n, double psi[])
{
    double ** returned = calloc(n, sizeof(double *));

    return returned;
}