#ifndef VMPCM_H_   
#define VMPCM_H_

double ** vmpcm(int n, int m, double tau[n][1], double x_guess[n][m], double omega1, double omega2, double errTol);
double * chebyshevPolynomial(double k[], double tau[]);

#endif