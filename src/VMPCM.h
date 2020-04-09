#ifndef VMPCM_H_   /* Include guard */
#define VMPCM_H_

double * vmpcm(double ode, double tau, double x_guess[], double omega1, double omega2, double errTol, double varargin);  /* An example function declaration */
double chebyshevPolynomial(double k, double tau);

#endif