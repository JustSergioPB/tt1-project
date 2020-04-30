#ifndef PICARDCHEBYSHEVDEMO_H_ 
#define PICARDCHEBYSHEVDEMO_H_

void picardChebyshevDemo();
void twoBodyForceModel(int rows, int columns, double *t, double **posvel, double mu, double ***f);
void plotPositionAndVelocity(double **rvPCM, double **rA, double **vA, double vMag, double a, double *t, double **xg);
void plotMagnitudeErrors(double *t, double *PosErr, double *VelErr);

#endif