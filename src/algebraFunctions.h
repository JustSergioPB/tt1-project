#ifndef ALGEBRAFUNCTIONS_H_ 
#define ALGEBRAFUNCTIONS_H_
void printMatriz(double **mat, int filas, int colum);
void printArray(double *a, int length);

void freeMatrix(int rows, double **matrix);
void getColumn(int rows, int columnNumber, double **matrix, double *column);
void getRow(int columns, int rowNumber, double **matrix, double *row);
void matrixPow(int rows, int columns, int coef, double **matrix, double ***result);
void sumMatrixRows(int rows, int columns, double **matrix, double *result);
void timesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result);
void dividesArrayMatrix(int rows, int columns, double *a, double **matrix, double ***result);
void addMatrixs(int rows, int columns, double **a, double **b, double ***result);
void substractMatrixs(int rows, int columns, double **a, double **b, double ***result);
void multiplyMatrixs(int rowsMatrixA, int colsMatrixA, int colsMatrixB, double **matrixA, double **matrixB, double ***result);
void crossProductMatrix(int rows, int columns, double **matrixA, double **matrixB, double ***result);
void dotProductMatrix(int rows, int columns, double **matrixA, double **matrixB, double *result);
void getTrueColumns(int rows, int columns, int *logicArray, double **matrixA, int resultColumns, double ***result);
void getRows(int columns, int from, int until, double **matrix, double ***result);
void multiplyMatrixByScalar(int rows, int columns, double scalar, double **matrix, double ***result);

void generateOnesArray(int length, double *a);
void generateIntegerArray(int from, int length, double *a);
void elemGreaterThanValue(int length, double value, double *a, int *result);
void elemLowerThanValue(int length, double value, double *a, int *result);
void absArray(int length, double *a, double *result);
int truesInArray(int length, int *a);
int sign(double num);
int any(int length, int *a);
void crossProductArray(double *a, double *b, double *cross);
double dotProductArray(int length, double *a, double *b);
void addScalarToArray(int length, double *a, double scalar, double *result);
void multiplyArrayByScalar(int length, double *a, double scalar, double *result);
void divideArrayByScalar(int length, double *a, double scalar, double *result);

#endif