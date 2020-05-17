#ifndef VMPCM_H_   
#define VMPCM_H_

void vmpcm(int n, int columns, double *tau, double ***x_guess, double omega1, double omega2, double errorTolerance, double varargin);
void chebyshevPolynomial(int sizeK, int sizeTau, double *k, double *tau, double ***tK);


#endif