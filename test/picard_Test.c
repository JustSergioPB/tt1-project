#include "picard_Test.h"
#include "picardChebyshevDemo.h"
#include "algebraFunctions.h"
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
            if(i == j || i == j+3){
                x_guess[i][j] = 1;
            } else {
                x_guess[i][j] = 0;
            }
        }
    }

    double **f;

    twoBodyForceModel(3,6,t,x_guess, mu, &f);

    double expected[3][6] = {
            {1e6 * 0.0249, 1e6 * 1.1614, 1e6 * 1.5238, 0,0,0},
            {1e6 * 0.0249, 1e6 * 1.1614, 1e6 * 1.5238, 0,0,0},
            {1e6 * 0.0249, 1e6 * 1.1614, 1e6 * 1.5238, 0,0,0}
    };

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 6; j++){
            assert(f[i][j] == expected[i][j]);
        }
    }

    freeMatrix(3, f);

    return 0;
}
