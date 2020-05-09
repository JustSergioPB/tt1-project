#include <stdio.h>
#include "picardChebyshevDemo.h"
#include "test/kepler_Test.h"
#include "test/algebraFun_Test.h"
#include "test/VMPCM_Test.h"
#include "test/picard_Test.h"

int main() {
    //algebraFunctions testing functions
    matrixPow_Test();
    sumMatrixRows_Test();
    elemGreaterThanValue_Test();
    elemLowerThanValue_Test();
    absArray_Test();
    any_Test();
    truesInArray_Test();
    crossProductArray_Test();
    getColumn_Test();
    crossProductMatrix_Test();
    getTrueColumns_Test();
    arrayDotProduct_Test();
    matrixDotProduct_Test();
    generateIntegerArray_Test();
    generateOnesArray_Test();
    timesArrayMatrix_Test();
    substractMatrixs_Test();
    dividesArrayMatrix_Test();
    //keplerUniversal testing functions
    //c2c3_Test();
    //keplerUniversal_Test();

    //VMPCM testing functions
    //VMPCM_Test();
    //chebyshevPolynomial_Test();

    //picardChebyshev testing functions
    //picardChebyshevDemo_Test();
    //twoBodyForceModel_Test();

   return 0;
}