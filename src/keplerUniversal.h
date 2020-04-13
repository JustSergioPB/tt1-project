#ifndef KEPLERUNIVERSAL_H_ 
#define KEPLERUNIVERSAL_H_

double ** keplerUniversal(int n, double r0[3][n], double v0[3][n], double timeVector[1][n], double mu);
double ** c2c3(int n, double psi[]);

#endif