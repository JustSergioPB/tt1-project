#include "keplerUniversal.h"
#include "algebraFunctions.h"
#include <math.h>

/**
* Most efficient way to propagate any type of two body orbit using kepler's equations.
*
* @param rows matrixs column's number
* @param columns matrixs column's number
* @param r0 [3 x n] matrix, position Vector in ECI coordinate frame of reference
* @param v0 [3 x n] matrix, velocity Vector in ECI coordinate frame of reference
* @param timeVector [1 x n] matrix, time vector in seconds
* @param mu Gravitional Constant, if not specified value is Earth's mu constant
*
*/
void keplerUniversal(int rows, int columns, double **r0, double **v0, double *timeVector, double mu, double ***rA, double ***vA){
    
    double tolerance = 1e-9;
    
    double **v0Pow2;
    double v0Pow2Sum[columns];
    double v0Mag[columns];

    matrixPow(rows, columns, 2, v0, &v0Pow2);
    sumMatrixRows(rows, columns, v0Pow2, v0Pow2Sum);

    double **r0Pow2;
    double r0pow2Sum[columns];
    double r0Mag[columns];

    matrixPow(rows, columns, 2, r0, &r0Pow2);
    sumMatrixRows(rows, columns, r0Pow2, r0pow2Sum);

    double alpha[columns];

    for(int i=0; i < columns; i++){
        r0Mag[i] = sqrt(r0pow2Sum[i]);
        v0Mag[i] = sqrt(v0Pow2Sum[i]);
        alpha[i] = -pow(v0Mag[i],2)/mu + 2/r0Mag[i];
    }

    double x0[columns];

    int idx[columns];
    elemGreaterThanValue(columns, 0.000001, alpha, idx);
    
    // Check if there are any Eliptic/Circular orbits
    if(any(columns, idx) == 1){
        calculateElipticCircularOrbits(columns, idx, mu, timeVector, alpha, x0);
    }
    
    double absAlpha[columns];
    absArray(columns, alpha, absAlpha);
    elemLowerThanValue(columns, 0.000001, absAlpha, idx);
    //Check if there are any Parabolic orbits
    if(any(columns, idx) == 1){
        calculateParabolicOrbits(rows, columns, idx, r0, v0, timeVector, mu, x0);
    }

    //Check if there are any Hyperbolic orbits
    elemLowerThanValue(columns, -0.000001, alpha, idx);
    if(any(columns, idx) == 1){
        calculateHyperbolicOrbits(rows, columns, idx, r0, v0, alpha, timeVector, r0Mag, mu, x0);
    }

    double dotr0v0[columns];
    double dr0v0Smu[columns];
    double Smut[columns];

    dotProductMatrix(rows, columns, r0, v0, dotr0v0);
    divideArrayByScalar(columns, dotr0v0, sqrt(mu), dr0v0Smu);
    multiplyArrayByScalar(columns, timeVector, sqrt(mu), Smut);

    double x02[columns]; 
    double x03[columns];
    double c2[columns]; 
    double c3[columns];
    double psi[columns];
    double r[columns];
    double xn[columns];
    double X0tOmPsiC3[columns];
    double X02tC2[columns];

    double error[columns];
    for(int i = 0; i < columns; i++ ){
        error[i] = INFINITY;
    }

    int a[columns];
    double absError[columns];
    elemGreaterThanValue(columns, tolerance, error, a);
    while(any(columns, a) == 1){
        for(int i = 0; i < columns; i++){
            x02[i] = pow(x0[i], 2);
            x03[i] = x02[i]*x0[i];
            psi[i] = x02[i]*alpha[i];
            c2c3(psi[i], &c2[i], &c3[i]);
            X0tOmPsiC3[i] = x0[i]*(1 - psi[i]*c3[i]);
            X02tC2[i] = x02[i]*c2[i];
            r[i] = X02tC2[i] + dr0v0Smu[i]*X0tOmPsiC3[i] + r0Mag[i]*(1 - psi[i]*c2[i]);
            xn[i] = x0[i] + (Smut[i] - x03[i]*c3[i] - dr0v0Smu[i]*X02tC2[i] - r0Mag[i]*X0tOmPsiC3[i])/r[i];
            error[i] = xn[i] - x0[i];
            x0[i] = xn[i];
        }

        absArray(columns, error, absError);
        elemGreaterThanValue(columns, tolerance, absError, a);
    }

    double f[columns];
    double g[columns];
    double gdot[columns];
    double fdot[columns];

    for(int i=0; i < columns; i++){
        f[i] = 1 - pow(xn[i], 2)*c2[i]/r0Mag[i];
        g[i] = timeVector[i] - pow(xn[i], 3)*c3[i]/sqrt(mu);
        gdot[i] = 1 - c2[i]*pow(xn[i], 2)/r[i];
        fdot[i] = xn[i]*(psi[i]*c3[i]-1)*sqrt(mu)/(r[i]*r0Mag[i]);
    }

    double **rFinal;
    double **vFinal;
    double **fr0;
    double **gv0;
    double **fdotr0;
    double **gdotv0;

    timesArrayMatrix(rows, columns, f, r0, &fr0);
    timesArrayMatrix(rows, columns, g, v0, &gv0);
    addMatrixs(rows, columns, fr0, gv0, &rFinal);

    timesArrayMatrix(rows, columns, fdot, r0, &fdotr0);
    timesArrayMatrix(rows, columns, gdot, v0, &gdotv0);
    addMatrixs(rows, columns, fdotr0, gdotv0, &vFinal);

    freeMatrix(rows, v0Pow2);
    freeMatrix(rows, r0Pow2);
    freeMatrix(rows, fr0);
    freeMatrix(rows, gv0);
    freeMatrix(rows, fdotr0);
    freeMatrix(rows, gdotv0);

    *rA = rFinal;
    *vA = vFinal;
}

/**
 *
 * @param columns (in)
 * @param idx (in)
 * @param mu (in)
 * @param timeVector (in)
 * @param alpha (in)
 * @param x0 (in/out)
 */
void calculateElipticCircularOrbits(int columns, int *idx, double mu, double *timeVector, double *alpha, double *x0){
    for(int i = 0; i < columns; i++){
        if(idx[i] == 1){
            x0[i] = sqrt(mu)*timeVector[i]*alpha[i];
        }
    }
}

/**
 *
 * @param rows (in)
 * @param columns (in)
 * @param idx (in)
 * @param r0 (in)
 * @param v0 (in)
 * @param timeVector (in)
 * @param mu (in)
 * @param x0 (in/out)
 */
void calculateParabolicOrbits(int rows, int columns, int *idx, double **r0, double **v0, double *timeVector, double mu, double *x0){
    int col = truesInArray(columns, idx);
    double **h;
    double **r0idx;
    double **v0idx;
    double **hPow2;
    double hCompressed[columns];
    double hMag[columns];
    double p[columns];
    double s[columns];
    double w[columns];

    getTrueColumns(rows, columns, idx, r0, col, &r0idx);
    getTrueColumns(rows, columns, idx, v0, col, &v0idx);
    crossProductMatrix(rows, col, r0idx, v0idx, &h);
    matrixPow(rows, columns, 2, h, &hPow2);
    sumMatrixRows(rows, columns, hPow2, hCompressed);

    for(int i = 0; i < columns; i++){
        hMag[i] = sqrt(hCompressed[i]);
        p[i] = pow(hMag[i],2)/mu;
        if(idx[i] == 1) s[i] = (1/(1/tan(3*sqrt(mu/pow(p[i], 3)))))*timeVector[i]/2;
        w[i] = atan(pow(tan(s[i]), 1/3));
        if(idx[i] == 1) x0[i] = sqrt(p[i])*2*(1/tan(2*w[i]));
    }

    freeMatrix(rows, h);
    freeMatrix(rows, hPow2);
    freeMatrix(rows, r0idx);
    freeMatrix(rows, v0idx);
}

/**
 *
 * @param rows (in)
 * @param columns (in)
 * @param idx (in)
 * @param r0 (in)
 * @param v0 (in)
 * @param alpha (in)
 * @param timeVector (in)
 * @param r0Mag (in)
 * @param mu (in)
 * @param x0 (in/out)
 */
void calculateHyperbolicOrbits(int rows, int columns, int *idx, double **r0, double **v0, double *alpha, double *timeVector, double *r0Mag, double mu, double *x0){
    int col = truesInArray(columns, idx);
    double **r0idx;
    double **v0idx;

    getTrueColumns(rows, columns, idx, r0, col, &r0idx);
    getTrueColumns(rows, columns, idx, v0, col, &v0idx);

    double dot[col];
    dotProductMatrix(rows, col, r0idx, v0idx, dot);

    for(int i =0; i < columns; i++){
        if(idx[i] == 1){
            double a = 1/alpha[i];
            x0[i] = sign(timeVector[i])*sqrt(-a)*log(-2*mu*alpha[i]*timeVector[i]/(dot[i] + sign(timeVector[i])*sqrt(-mu*a)*(1 - r0Mag[i]*alpha[i])));
        }
    }

    freeMatrix(rows, r0idx);
    freeMatrix(rows, v0idx);
}

/**
 *
 * @param (in) psi
 * @param (out) c2
 * @param (out) c3
 */
void c2c3(double psi, double *c2, double *c3)
{

    if(psi > 1e-6){
        *c2 = (1-cos(sqrt(psi)))/psi;
        *c3 = (sqrt(psi) - sin(sqrt(psi)))/sqrt(pow(psi,3));
    }

    if(psi < -1e-6){
        *c2 = (1 - cosh(sqrt(-psi)))/psi;
        *c3 = (sinh(sqrt(-psi)) - sqrt(-psi))/sqrt(pow(-psi,3));
    }

    if(fabs(psi) <= 1e-6){
        *c2 = 0.5;
        *c3 = 1.0/6.0;
    }
}