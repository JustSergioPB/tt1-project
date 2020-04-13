#include "LinearAlgebraFunctions.h"
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

/**
* Adds two arrays returning c = [a[0]+b[0], ... , a[n]+b[n]]
*
* @param size size of returning array
* @param a
* @param b
*/
double * addArrays(int size, double a[], double b[]) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i] + b[i];
    }

    return c;
}

/**
* Substracts two arrays returning c = [a[0]-b[0], ... , a[n]-b[n]]
*
* @param size size of returning array
* @param a
* @param b
*/
double * substractArrays(int size, double a[], double b[]) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i] - b[i];
    }

    return c;
}

/**
* Multiplies two arrays returning c = [a[0]*b[0], ... , a[n]*b[n]]
*
* @param size size of returning array
* @param a
* @param b
*/
double * mulArrays(int size, double a[], double b[]) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i]*b[i];
    }

    return c;
}

/**
* Divides two arrays returning c = [a[0]/b[0], ... , a[n]/b[n]]
*
* @param size size of returning array
* @param a
* @param b
*/
double * divArrays(int size, double a[], double b[]) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i]/b[i];
    }

    return c;
}

/**
* Adds a scalar to a vector returning c = [a[0]+scalar, ... , a[n]+scalar]
*
* @param size size of returning array
* @param a
* @param scalar
*/
double * addScalarToArray(int size, double a[], double scalar) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i] + scalar;
    }

    return c;
}

/**
* Substracts a scalar to a vector returning c = [a[0]-scalar, ... , a[n]-scalar]
*
* @param size size of returning array
* @param a
* @param scalar
*/
double * substractScalarToArray(int size, double a[], double scalar) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i] - scalar;
    }

    return c;
}

/**
* Multiplies a vector by a scalar returning c = [a[0]*scalar, ... , a[n]*scalar]
*
* @param size size of returning array
* @param a
* @param scalar
*/
double * mulArrayByScalar(int size, double a[], double scalar) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i]*scalar;
    }

    return c;
}

/**
* Divides a vector by a scalar returning c = [a[0]+scalar, ... , a[n]+scalar]
*
* @param size size of returning array
* @param a
* @param scalar
*/
double * divArrayByScalar(int size, double a[], double scalar) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = a[i]/scalar;
    }

    return c;
}

/**
* Divides a vector by a scalar returning c = [a[0]+scalar, ... , a[n]+scalar]
*
* @param size size of returning array
* @param a
* @param scalar
*/
double * powArray(int size, double a[], double coef) {
    double *c = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        c[i] = pow(a[i], coef);
    }

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
    double *subset = malloc((end - start)*sizeof(double));

    for(int i = start; i < (end - start); i++){
        subset[i] = a[i];
    }

    return subset;
}

/**
* Generates an array with integer numbers returning integerArray = [from, from + 1 , ... , until]
*
* @param from
* @param until
*/
double * generateIntegerArray(int from, int until) {
    double *integerArray = malloc((until + 1)*sizeof(double));

    for(int i = 0; i < until; i++){
        integerArray[i] = from;
        from++;
    }

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
* @param size size of returning array
* @param a
*/
double * sign(int size, double a[]) {
    double *singArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        if(a[i] > 0){
            singArray[i] = 1;
        } else if(a[i] < 0) {
            singArray[i] = -1;
        } else if(a[i] == 0) {
            singArray[i] = 0;
        }
    }

    return singArray;
}

/**
* Generates an array containing absolute from a values absArray= [abs(a[1]), ... , abs(a[n])]
*
* @param size size of returning array
* @param a
*/
double * absArray(int size, double a[]) {
    double *absArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        absArray[i] = abs(a[i]);
    }

    return absArray;
}

/**
* Generates an array containing cos values from a values cosArray= [cos(a[1]), ... , cos(a[n])]
*
* @param size size of returning array
* @param a
*/
double * cosArray(int size, double a[]) {
    double *cosArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        cosArray[i] = cos(a[i]);
    }

    return cosArray;
}

/**
* Generates an array containing acos values from a values acosArray= [acos(a[1]), ... , acos(a[n])]
*
* @param size size of returning array
* @param a
*/
double * acosArray(int size, double a[]) {
    double *acosArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        acosArray[i] = 1 / cos(a[i]);
    }

    return acosArray;
}

/**
* Generates an array containing cosh values from a values coshArray= [cosh(a[1]), ... , cosh(a[n])]
*
* @param size size of returning array
* @param a
*/
double * coshArray(int size, double a[]) {
    double *coshArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        coshArray[i] = cosh(a[i]);
    }

    return coshArray;
}

/**
* Generates an array containing sin values from a values sinArray= [cos(a[1]), ... , cos(a[n])]
*
* @param size size of returning array
* @param a
*/
double * sinArray(int size, double a[]) {
    double *sinArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        sinArray[i] = sin(a[i]);
    }

    return sinArray;
}

/**
* Generates an array containing sinh values from a values sinhArray= [sinh(a[1]), ... , sinh(a[n])]
*
* @param size size of returning array
* @param a
*/
double * sinhArray(int size, double a[]) {
    double *sinhArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        sinhArray[i] = sinh(a[i]);
    }

    return sinhArray;
}

/**
* Generates an array containing tan values from a values tanArray= [cos(a[1]), ... , cos(a[n])]
*
* @param size size of returning array
* @param a
*/
double * tanArray(int size, double a[]) {
    double *tanArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        tanArray[i] = tan(a[i]);
    }

    return tanArray;
}

/**
* Generates an array containing sqrt values from a values, sqrtArray= [sqrt(a[1]), ... , sqrt(a[n])]
*
* @param size size of returning array
* @param a
*/
double * sqrtArray(int size, double a[]) {
    double *sqrtArray = malloc(size*sizeof(double));

    for(int i = 0; i < size; i++){
        sqrtArray[i] = sqrt(a[i]);
    }

    return sqrtArray;
}

/**
* Returns max value contained in a
*
* @param size size of array
* @param a
*/
double max(int size, double a[]) {
    double max = 0;
    return max;
}

/**
* Returns array's elements value contained in a
*
* @param size size of array
* @param a
*/
double sumArrElemens(int size, double a[]){
    double sum = 0.0;

    for(int i = 0; i < size; i++){
        sum = sum + a[i];
    }

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
* @param size size of array
* @param a
*/
double * acotArray(int size, double a[]){
    double *acotArray = malloc(size*sizeof(double));
    return acotArray;
}

/**
* Generates an array containing atan values from a values, atanArray= [atan(a[1]), ... , atan(a[n])]
*
* @param size size of array
* @param a
*/
double * atanArray(int size, double a[]){
    double *atanArray = malloc(size*sizeof(double));
    return atanArray;
}

/**
* Generates an array containing log values from a values, logArray= [log(a[1]), ... , log(a[n])]
*
* @param size size of array
* @param a
*/
double * logArray(int size, double a[]){
    double *logArray = malloc(size*sizeof(double));
    return logArray;
}

/**
* Generates an array containing 0 , 1 values result of a[n] > value
*
* @param size size of array
* @param a
* @param value
*/
int * elemGreaterThanValue(int size, double a[], double value){
    int *boolArray = malloc(size*sizeof(int));
    return boolArray;
}


/**
* Generates an array containing 0 , 1 values result of a[n] < value
*
* @param size size of array
* @param a
* @param value
*/
int * elemLowerThanValue(int size, double a[], double value){
    int *boolArray = malloc(size*sizeof(int));
    return boolArray;
}

/**
* Generates a array with 1s of size n 
*
* @param size size of array
* @param n size of array
*/
int * generateOnesArray(int size){
    int *ones = malloc(size*sizeof(int));

    for(int i = 0; i < size; i++){
        ones[i] = 1;
    }

    return ones;
}