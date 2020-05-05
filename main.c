#include <stdio.h>
#include "picardChebyshevDemo.h"
#include "test/kepler_Test.h"
#include "test/algebraFun_Test.h"

int main() {
    //algebraFunctions testing functions
    matrixPow_Test();
    sumMatrixRows_Test();
    //keplerUniversal testing functions
    keplerUniversal_Test();
    c2c3_Test();


   return 0;
}