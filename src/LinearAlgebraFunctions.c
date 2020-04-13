#include "LinearAlgebraFunctions.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* Adds two arrays returning c = [a[0]+b[0], ... , a[n]+b[n]]
*
* @param a
* @param b
*/
double * addArrays(double a[], double b[]) {
    double *c = malloc(1);
    return c;
}

/**
* Substracts two arrays returning c = [a[0]-b[0], ... , a[n]-b[n]]
*
* @param a
* @param b
*/
double * substractArrays(double a[], double b[]) {
    double *c = malloc(1);
    return c;
}

/**
* Multiplies two arrays returning c = [a[0]*b[0], ... , a[n]*b[n]]
*
* @param a
* @param b
*/
double * mulArrays(double a[], double b[]) {
    double *c = malloc(1);
    return c;
}

/**
* Divides two arrays returning c = [a[0]/b[0], ... , a[n]/b[n]]
*
* @param a
* @param b
*/
double * divArrays(double a[], double b[]) {
    double *c = malloc(1);
    return c;
}

/**
* Adds a scalar to a vector returning c = [a[0]+scalar, ... , a[n]+scalar]
*
* @param a
* @param scalar
*/
double * addScalarToArray(double a[], double scalar) {
    double *c = malloc(1);
    return c;
}

/**
* Substracts a scalar to a vector returning c = [a[0]-scalar, ... , a[n]-scalar]
*
* @param a
* @param scalar
*/
double * substractScalarToArray(double a[], double scalar) {
    double *c = malloc(1);
    return c;
}

/**
* Multiplies a vector by a scalar returning c = [a[0]*scalar, ... , a[n]*scalar]
*
* @param a
* @param scalar
*/
double * mulArrayByScalar(double a[], double scalar) {
    double *c = malloc(1);
    return c;
}

/**
* Divides a vector by a scalar returning c = [a[0]+scalar, ... , a[n]+scalar]
*
* @param a
* @param scalar
*/
double * divArrayByScalar(double a[], double scalar) {
    double *c = malloc(1);
    return c;
}

/**
* Generates a subset from an array returning subset = [a[start], ... , a[end]]
*
* @param start
* @param end
* @param a
*/
double * getArraySubset(int start, int end, double a[]){
    double *subset = malloc(1);
    return subset;
}

/**
* Generates an array with integer numbers returning integerArray = [from, from + 1 , ... , until]
*
* @param from
* @param until
*/
double * generateIntegerArray(int from, int until) {
    double *integerArray = malloc(1);
    return integerArray;
}

/**
* Generates an array containing the following elements
* 1 if the corresponding element of a is greater than 0.
*
* 0 if the corresponding element of a equals 0.
*
* -1 if the corresponding element of a is less than 0.
*
* @param a
*/
double * sign(double a[]) {
    double *integerArray = malloc(1);
    return integerArray;
}

/**
* Generates an array containing absolute from a values absArray= [abs(a[1]), ... , abs(a[n])]
*
* @param a
*/
double * absArray(double a[]) {
    double *absArray = malloc(1);
    return absArray;
}

/**
* Generates an array containing cos values from a values cosArray= [cos(a[1]), ... , cos(a[n])]
*
* @param a
*/
double * cosArray(double a[]) {
    double *cosArray = malloc(1);
    return cosArray;
}

/**
* Generates an array containing acos values from a values acosArray= [acos(a[1]), ... , acos(a[n])]
*
* @param a
*/
double * acosArray(double a[]) {
    double *acosArray = malloc(1);
    return acosArray;
}

/**
* Generates an array containing cosh values from a values coshArray= [cosh(a[1]), ... , cosh(a[n])]
*
* @param a
*/
double * coshArray(double a[]) {
    double *coshArray = malloc(1);
    return coshArray;
}

/**
* Generates an array containing sin values from a values sinArray= [cos(a[1]), ... , cos(a[n])]
*
* @param a
*/
double * sinArray(double a[]) {
    double *sinArray = malloc(1);
    return sinArray;
}

/**
* Generates an array containing sinh values from a values sinhArray= [sinh(a[1]), ... , sinh(a[n])]
*
* @param a
*/
double * sinhArray(double a[]) {
    double *sinhArray = malloc(1);
    return sinhArray;
}

/**
* Generates an array containing tan values from a values tanArray= [cos(a[1]), ... , cos(a[n])]
*
* @param a
*/
double * tanArray(double a[]) {
    double *tanArray = malloc(1);
    return tanArray;
}

/**
* Generates an array containing sqrt values from a values, sqrtArray= [sqrt(a[1]), ... , sqrt(a[n])]
*
* @param a
*/
double * sqrtArray(double a[]) {
    double *sqrtArray = malloc(1);
    return sqrtArray;
}

/**
* Returns max value contained in a
*
* @param a
*/
double max(double a[]) {
    double max = 0;
    return max;
}

/**
* Returns array's elements value contained in a
*
* @param a
*/
double sumArrElemens(double a[]){
    double sum = 0.0;
    return sum;
}

/**
* Returns cross product from a and b
*
* @param a
* @param b
*/
double * crossProduct(double a[], double b[]){
    double *crossProduct = malloc(1);
    return crossProduct;
}

/**
* Generates an array containing acot values from a values, acotArray= [acot(a[1]), ... , acot(a[n])]
*
* @param a
*/
double * acotArray(double a[]){
    double *acotArray = malloc(1);
    return acotArray;
}

/**
* Generates an array containing atan values from a values, atanArray= [atan(a[1]), ... , atan(a[n])]
*
* @param a
*/
double * atanArray(double a[]){
    double *atanArray = malloc(1);
    return atanArray;
}

/**
* Generates an array containing log values from a values, logArray= [log(a[1]), ... , log(a[n])]
*
* @param a
*/
double * logArray(double a[]){
    double *logArray = malloc(1);
    return logArray;
}

/**
* Generates an array containing 0 , 1 values result of a[n] > value
*
* @param a
* @param value
*/
int * elemGreaterThanValue(double a[], double value){
    int *boolArray = malloc(1);
    return boolArray;
}


/**
* Generates an array containing 0 , 1 values result of a[n] < value
*
* @param a
* @param value
*/
int * elemLowerThanValue(double a[], double value){
    int *boolArray = malloc(1);
    return boolArray;
}