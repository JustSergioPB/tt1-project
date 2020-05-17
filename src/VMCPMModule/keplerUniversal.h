#ifndef KEPLERUNIVERSAL_H_ 
#define KEPLERUNIVERSAL_H_

void keplerUniversal(int rows, int columns, double **r0, double **v0, double *timeVector, double mu, double ***rA, double ***vA);
void c2c3(double psi, double *c2, double *c3);
void calculateElipticCircularOrbits(int columns, int *idx, double mu, double *timeVector, double *alpha, double *x0);
void calculateParabolicOrbits(int rows, int columns, int *idx, double **r0, double **v0, double *timeVector, double mu, double *x0);
void calculateHyperbolicOrbits(int rows, int columns, int *idx, double **r0, double **v0, double *alpha, double *timeVector, double *r0Mag, double mu, double *x0);

#endif