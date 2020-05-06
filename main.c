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
    //keplerUniversal testing functions
    //keplerUniversal_Test();
    //c2c3_Test();
    //VMPCM testing functions
    //VMPCM_Test();
    chebyshevPolynomial_Test();
    //picardChebyshev testing functions
    picardChebyshevDemo_Test();
    twoBodyForceModel_Test();

   return 0;
}