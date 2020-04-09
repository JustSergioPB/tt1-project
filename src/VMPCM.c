#include "VMPCM.h"

double * vmpcm(double ode, double tau, double x_guess[], double omega1, double omega2, double errTol, double varargin){
    double returnedArr[2];
    //TODO check this value, probably it is x_guess[] entry parameter
    double x_guess_var = 0.0;
    double iter = 0.0;

    returnedArr[0] = x_guess_var;
    returnedArr[1] = iter;

    return returnedArr;
} 

double chebyshevPolynomial(double k, double tau)
{
    double returnedValue = 0.0;
    return returnedValue;
}