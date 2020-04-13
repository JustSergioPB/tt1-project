#ifndef PICARDCHEBYSHEVDEMO_H_ 
#define PICARDCHEBYSHEVDEMO_H_

void picardChebyshevDemo();
double * twoBodyForceModel(double t, double posvel[], double mu);
void plotPositionAndVelocity(double rvPCM, double rA, double vA, double vMag, double a, double t, double xg);
void plotMagnitudeErrors(double t, double PosErr, double VelErr);

#endif