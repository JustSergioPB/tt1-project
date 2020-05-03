#ifndef AUXMETHODS_H_ 
#define AUXMETHODS_H_

void freeMatrix(int rows, double **matrix);
void getColumn(int rows, int columnNumber, double **matrix, double *column);
int truesInArray(int length, int *a);
void matrixPow(int rows, int columns, int coef, double **matrix, double ***result);
void arrayPow(int length, int coef, double *a, double *result);
void compressToOneDim(int rows, int columns, double **matrix, double *result);
void elemGreaterThanValue(int length, double value, double *a, int *result);
void elemLowerThanValue(int length, double value, double *a, int *result);
void elemLowerOrEqualThanValue(int length, double value, double *a, int *result);
void absArray(int length, double *a, double *result);
void multiplyArrays(int length, double *a, double *b, double *result);
int sign(double num);
double dotProduct(int rows, int columns, double **matrixA, double **matrixB);
void timesArrayArray(int lengthA, int lenghtB, double *a, double *b, double ***result);
void timesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result);
void dividesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result);
void addMatrixs(int rows, int columns, double **a, double **b, double ***result);
void substractMatrixs(int rows, int columns, double **a, double **b, double ***result);
int any(int length, int *a);
void crossProduct(int length, double *a, double *b, double *cross);
double sumArrayElements(int length, double *a);
void multiplyArrayByScalar(int length, double *a, double scalar, double *result);
void divideArrayByScalar(int length, double *a, double scalar, double *result);
void addArrays(int length, double *a, double *b, double *result);
void addScalarToArray(int length, double *a, double scalar, double *result);
void transpose(int rows, int columns, double **source, double ***transposed);
void generateIntegerArray(int from, int length, double *a);
void generateOnesArray(int length, double *a);

#endif