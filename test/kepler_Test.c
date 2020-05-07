#include "keplerUniversal.h"
#include <assert.h>
#include "kepler_Test.h"
#include <stdio.h>
#include <stdlib.h>
#include "algebraFunctions.h"

int keplerUniversal_Test(){

    printf("keplerUniversal_test started running");
    double **r0 = calloc(3, sizeof(double *));
    double **v0 = calloc(3, sizeof(double *));
    for(int i = 0; i < 3; i++){
        r0[i] = calloc(3, sizeof(double ));
        v0[i] = calloc(3, sizeof(double ));
        for(int j = 0; j < 3; j++){
            if(i == j){
                r0[i][j] = 1;
                v0[i][j] = 1;
            } else{
                r0[i][j] = 0;
                v0[i][j] = 0;
            }
        }
    }

    double **rFin;
    double **vFin;
    double t[3] = {1,2,3};
    double mu = 398600.4418;

    keplerUniversal(3, 3, r0, v0, t, mu, &rFin, &vFin);

    double rExpected[3][3] =
            {{0.8921,0,0},
             {0,0.4935,0},
             {0,0,0.5766}};
    double vExpected[3][3] =
            {{-310.4531,0,0},
             {0,-904.6343,0},
             {0,0,765.1355}};

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            assert(rExpected[i][j] == rFin[i][j]);
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            assert(vExpected[i][j] == vFin[i][j]);
        }
    }

    freeMatrix(3, r0);
    freeMatrix(3, v0);

    printf("keplerUniversal_test run with no troubles");
    return 0;
}

int c2c3_Test(){
    printf("c2c3_test started running");
    double t[3] = {1,2,3};
    double c2[3];
    double c3[3];

    for(int i = 0; i < 3; i++){
        c2c3S(t[i], &c2[i], &c3[i]);
    }

    double c2Expected[3] = {0.4597, 0.4220, 0.3869};
    double c3Expected[3] = {0.1585, 0.1508, 0.1434};

    for(int i = 0; i < 3; i++){
        assert(c2Expected[i] == c2[i]);
    }

    for(int i = 0; i < 3; i++){
        assert(c3Expected[i] == c3[i]);
    }

    printf("c2c3_test run with no troubles");
    return 0;
}
