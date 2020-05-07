#ifndef KEPLERUNIVERSAL_H_ 
#define KEPLERUNIVERSAL_H_

void keplerUniversal(int rows, int columns, double **r0, double **v0, double *timeVector, double mu, double ***rA, double ***vA);
void c2c3(int n, double *psi, double *c2, double *c3);
void c2c3S(double psi, double *c2, double *c3);

#endif