#ifndef ALGEBRAFUNCTIONS_H_ 
#define ALGEBRAFUNCTIONS_H_

void freeMatrix(int rows, double **matrix);
void getColumn(int rows, int columnNumber, double **matrix, double *column);
void matrixPow(int rows, int columns, int coef, double **matrix, double ***result);
void sumMatrixRows(int rows, int columns, double **matrix, double *result);
void timesArrayArray(int lengthA, int lenghtB, double *a, double *b, double ***result);
void timesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result);
void dividesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result);
void addMatrixs(int rows, int columns, double **a, double **b, double ***result);
void substractMatrixs(int rows, int columns, double **a, double **b, double ***result);
void transpose(int rows, int columns, double **source, double ***transposed);
void multiplyMatrixs(int rowsMatrixA, int colsMatrixA, int rowsMatrixB, int colsMatrixB, double **matrixA, double **matrixB, double ***result);
double matrixDotProduct(int rows, int columns, double **matrixA, double **matrixB);

void generateOnesArray(int length, double *a);
void generateIntegerArray(int from, int length, double *a);
void arrayPow(int length, int coef, double *a, double *result);
void elemGreaterThanValue(int length, double value, double *a, int *result);
void elemLowerThanValue(int length, double value, double *a, int *result);
void elemLowerOrEqualThanValue(int length, double value, double *a, int *result);
void absArray(int length, double *a, double *result);
void multiplyArrays(int length, double *a, double *b, double *result);
int truesInArray(int length, int *a);
int sign(double num);
int any(int length, int *a);
double arrayDotProduct(int length, double *a, double *b);
void crossProduct(int length, double *a, double *b, double *cross);
double sumArrayElements(int length, double *a);
void addScalarToArray(int length, double *a, double scalar, double *result);
void multiplyArrayByScalar(int length, double *a, double scalar, double *result);
void divideArrayByScalar(int length, double *a, double scalar, double *result);
void addArrays(int length, double *a, double *b, double *result);
void multiplyArrayByMatrix(int length, int rows, int columns, double *a, double **matrix, double *result);

#endif