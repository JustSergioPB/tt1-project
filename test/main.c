#include <stdio.h>
#include "VMCPMModule/picardChebyshevDemo.h"
#include "kepler_Test.h"
#include "algebraFun_Test.h"
#include "VMPCM_Test.h"
#include "picard_Test.h"

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
    getRows_Test();
    multiplyMatrixByScalar_Test();
    getRow_Test();
    multiplyMatrixs_Test();

    //keplerUniversal testing functions
    c2c3_Test();
    keplerUniversal_Test();

    //VMPCM testing functions
    VMPCM_Test();
    chebyshevPolynomial_Test();

    //picardChebyshev testing functions
    picardChebyshevDemo_Test();
    twoBodyForceModel_Test();

   return 0;
}
