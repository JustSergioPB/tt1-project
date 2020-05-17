#include "picard_Test.h"
#include "VMCPMModule/picardChebyshevDemo.h"
#include "VMCPMModule/algebraFunctions.h"
#include <stdlib.h>
#include <assert.h>

int picardChebyshevDemo_Test(){
    return 0;
}

int twoBodyForceModel_Test(){

    double omega1 = 0.5, omega2 = 0.5;
    double mu = 398600.4418;
    double t[3] = {1*omega2 + omega1, 2*omega2 + omega1, 3*omega2 + omega1};

    double **x_guess = (double **) calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        x_guess[i] = (double *) calloc(6, sizeof(double ));
        for(int j = 0; j < 6; j++){
            x_guess[i][j] = (i == j || i == j+3) ? 1 : 0;
        }
    }

    double **result;

    twoBodyForceModel(3,6,x_guess, mu, &result);

    double constant = 1e5;
    double expected[3][6] = {
            {0, 0, 0, -3.986 * constant,0,0},
            {0, 0, 0, 0,-3.986 * constant,0},
            {0, 0, 0, 0,0,-3.986 * constant}
    };

    printMatriz(result, 3,6);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            assert(result[i][j] == expected[i][j]);
        }
    }

    freeMatrix(3, result);

    return 0;
}
