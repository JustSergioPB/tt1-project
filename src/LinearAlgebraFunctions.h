#ifndef LINEARALGEBRAFUNCTIONS_H_ 
#define LINEARALGEBRAFUNCTIONS_H_

double * addArrays(int size, double a[], double b[]);
double * substractArrays(int size, double a[], double b[]);
double * mulArrays(int size, double a[], double b[]);
double * divArrays(int size, double a[], double b[]);
double * addScalarToArray(int size, double a[], double scalar);
double * substractScalarToArray(int size, double a[], double scalar);
double * mulArrayByScalar(int size, double a[], double scalar);
double * divArrayByScalar(int size, double a[], double scalar);
double * powArray(int size, double a[], double coef);
double * getArraySubset(int start, int end, double a[]);
double * generateIntegerArray(int from, int until);
double * sign(int size, double a[]);
double * absArray(int size, double a[]);
double * cosArray(int size, double a[]);
double * acosArray(int size, double a[]);
double * coshArray(int size, double a[]);
double * sinArray(int size, double a[]);
double * sinhArray(int size, double a[]);
double * tanArray(int size, double a[]);
double * sqrtArray(int size, double a[]);
double max(int size, double a[]);
double sumArrElemens(int size, double a[]);
double * crossProduct(double a[], double b[]);
double * acotArray(int size, double a[]);
double * atanArray(int size, double a[]);
double * logArray(int size, double a[]);
int * elemGreaterThanValue(int size, double a[], double value);
int * elemLowerThanValue(int size, double a[], double value);
int * generateOnesArray(int size);

#endif