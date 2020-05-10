#include "VMPCM_Test.h"
#include "VMPCM.h"
#include "algebraFunctions.h"
#include <assert.h>
#include <stdlib.h>

int VMPCM_Test(){
    double omega1 = 0.5, omega2 = 0.5;
    double mu = 398600.4418;
    double tau[3] = {1,2,3};
    double errTol = 1e-6;
    double **x_guess = (double **) calloc(3, sizeof(double *));

    for(int i = 0; i < 3; i++){
        x_guess[i] = (double *) calloc(6, sizeof(double ));
        for(int j = 0; j < 6; j++){
            x_guess[i][j] = (i == j || i == j+3) ? 1 : 0;
        }
    }

    vmpcm(3,6, tau, &x_guess, omega1, omega2, errTol, mu);

    double expected[3][6] = {
        {1e9*-0.0499, 1e9*-2.4295, 1e9*-3.1924, 0, 1e9*-0.0012, 1e9*-0.0015 },
        {1e9*-0.0499, 1e9*-2.4301, 1e9*-3.1932, 0, 1e9*-0.0012, 1e9*-0.0015},
        {1e9*-0.0498, 1e9*-2.4283, 1e9*-3.1909, 0, 1e9*-0.0012, 1e9*-0.0015}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            assert(x_guess[i][j] == expected[i][j]);
        }
    }

    freeMatrix(3, x_guess);

    return 0;
}

int chebyshevPolynomial_Test(){

    double tau[3] = {0,1,2};
    double k[4] = {0,1,2,3};
    double **tK;

    chebyshevPolynomial(4,3,k,tau, &tK);

    double expected[4][3] = {
            {1, 1, 1},
            {1, 2, 3},
            {1, 7, 17},
            {1, 26, 99}
    };

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 3; j++){
            assert(tK[i][j] == expected[i][j]);
        }
    }

    freeMatrix(4, tK);

    return 0;
}

