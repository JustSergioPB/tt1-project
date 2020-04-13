#ifndef LINEARALGEBRAFUNCTIONS_H_ 
#define LINEARALGEBRAFUNCTIONS_H_

double * addArrays(double a[], double b[]);
double * substractArrays(double a[], double b[]);
double * mulArrays(double a[], double b[]);
double * divArrays(double a[], double b[]);
double * addScalarToArray(double a[], double scalar);
double * substractScalarToArray(double a[], double scalar);
double * mulArrayByScalar(double a[], double scalar);
double * divArrayByScalar(double a[], double scalar);
double * getArraySubset(int start, int end, double a[]);
double * generateIntegerArray(int from, int until);
double * sign(double a[]);
double * absArray(double a[]);
double * cosArray(double a[]);
double * acosArray(double a[]);
double * coshArray(double a[]);
double * sinArray(double a[]);
double * sinhArray(double a[]);
double * tanArray(double a[]);
double * sqrtArray(double a[]);
double max(double a[]);
double sumArrElemens(double a[]);
double * crossProduct(double a[], double b[]);
double * acotArray(double a[]);
double * atanArray(double a[]);
double * logArray(double a[]);
int * elemGreaterThanValue(double a[], double value);
int * elemLowerThanValue(double a[], double value);

#endif