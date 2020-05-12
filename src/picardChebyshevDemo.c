#include "picardChebyshevDemo.h"
#include "algebraFunctions.h"
#include "keplerUniversal.h"
#include "VMPCM.h"
#include <stdlib.h>
#include <math.h>
#ifndef MPI
#define M_PI 3.14159265358979323846
#endif

/**Entry point for picarChebyShevDemo*/
void picardChebyshevDemo(){

   double mu = 398600.4415;
   double r0[3] = { 7000, 0 ,0};

   double rMag = 0.0;
   for(int i = 0; i < 3; i++){
       rMag += pow(r0[i], 2);
   }
   double param = sqrt(mu / rMag);
   double v0[3] = {0, param, 0};

   double vMag = 0.0;
   for(int i = 0; i < 3; i++){
       vMag += pow(v0[i], 2);
   }

   double p = 2*M_PI*sqrt(pow(rMag, 3) / mu);
   double tSpan[2] = {0, p*2};

   int n = 50;
   
   double tau[n+1];
   for(int i = 50, j = 0; i >= 0; i--){
      tau[j] = cos(j*M_PI/n);
      j++;  
   }

   double omega1 = (tSpan[1]+tSpan[0])/2;
   double omega2 = (tSpan[1]-tSpan[0])/2;
   double tauTimesOmega2[n+1];
   double t[n+1];
   double **r0Matr = (double **) calloc(3, sizeof(double *));
   double **v0Matr = (double **) calloc(3, sizeof(double *));

   multiplyArrayByScalar(n+1, tau, omega2, tauTimesOmega2);
   addScalarToArray(n+1, tauTimesOmega2, omega1, t);

   for(int i = 0; i < 3; i++){
       r0Matr[i] = (double *) calloc(n+1, sizeof(double ));
       v0Matr[i] = (double *) calloc(n+1, sizeof(double ));
       for(int j = 0; j < n+1; j++){
           r0Matr[i][j] = r0[i];
           v0Matr[i][j] = v0[i];
       }
   }

   double **rFinMatr;
   double **vFinMatr;

   keplerUniversal(3, n+1, r0Matr, v0Matr, t, mu, &rFinMatr, &vFinMatr);

   double errorTolerance = 1e-6;
   double noisePrct = 0.25;
   double **rFinMatrTransposed;
   double **vFinMatrTransposed;

   transpose(3, n+1, rFinMatr, &rFinMatrTransposed);
   transpose(3, n+1, vFinMatr, &vFinMatrTransposed);

   double **x_guess = (double **) calloc(n+1, sizeof(double *));

   for(int i = 0; i < n+1; i++){
       x_guess[i] = (double *) calloc(6, sizeof(double *));
       for(int j = 0; j < 6; j++){
           x_guess[i][j] = (j < 3) ? rFinMatrTransposed[i][j] + rand()*rMag*noisePrct*2 - rMag*noisePrct :
                           rFinMatrTransposed[i][j-3] + rand()*rMag*noisePrct*2 - rMag*noisePrct;
       }
   }
   
   // vmpcm(n+1, 3, tau, &x_guess, omega1, omega2, errorTolerance);

   double APosMag[n+1];
   double AVelMag[n+1];
   double PCMPosMag[n+1];
   double PCMVelMag[n+1];
   double PosErr[n+1];
   double VelErr[n+1];

    for(int i = 0; i < n+1; i++){
        APosMag[i] = 0.0;
        AVelMag[i] = 0.0;
        for(int j = 3; j < 3; j++ ){
            APosMag[i] += pow(rFinMatrTransposed[i][j], 2);
            AVelMag[i] += pow(vFinMatrTransposed[i][j], 2);
        }
        APosMag[i] = sqrt(APosMag[i]);
        AVelMag[i] = sqrt(AVelMag[i]);
    }

   for(int i = 0; i < n+1; i++){
      PCMPosMag[i] = 0.0;
      for(int j = 0; j < 3; j++ ){
         PCMPosMag[i] += sqrt(pow(x_guess[i][j], 2));
      }
   }

   for(int i = 0; i < n+1; i++){
      PCMVelMag[i] = 0.0;
      for(int j = 3; j < 6; j++ ){
         PCMVelMag[i] += sqrt(pow(x_guess[i][j], 2));
      }
   }

   for(int i= 0; i < n+1; i++){
      PosErr[i] = fabs(PCMPosMag[i] - APosMag[i]);
      VelErr[i] = fabs(PCMVelMag[i] - AVelMag[i]);
   }

   //plotPositionAndVelocity(rvPCM, rFinMatr, vFinMatr, vMag, rMag, t, x_guess);
   //plotMagnitudeErrors(t, PosErr, VelErr);

   freeMatrix(n+1, x_guess);
   freeMatrix(n+1, rFinMatrTransposed);
   freeMatrix(n+1, vFinMatrTransposed);
   freeMatrix(3, rFinMatr);
   freeMatrix(3, vFinMatr);
   freeMatrix(3, r0Matr);
   freeMatrix(3, v0Matr);
}


void twoBodyForceModel(int rows, int columns, double *t, double **posvel, double mu, double ***f){
   
   double **eta = (double **) calloc(rows, sizeof(double *));
   double rMag[rows];
   double nuR3[rows];

   for(int i = 0; i < rows; i++){
      eta[i] = (double *) calloc(columns, sizeof(double));

      rMag[i] = 0.0; 
      for(int j = 0; j < 3; j++){
         rMag[i] += pow(posvel[i][j], 2);
      }
      rMag[i] = sqrt(rMag[i]);

      nuR3[i] = -mu/pow(rMag[i], 3); 
      
      eta[i][0] = posvel[i][3];
      eta[i][1] = posvel[i][4];
      eta[i][2] = posvel[i][5];
      eta[i][3] = nuR3[i]*posvel[i][0];
      eta[i][4] = nuR3[i]*posvel[i][1];
      eta[i][5] = nuR3[i]*posvel[i][2];
   }

   *f = eta;
}

/**
* Print function
*/
void plotPositionAndVelocity(double **rvPCM, double **rA, double **vA, double vMag, double a, double *t, double **xg){

}

/**
* Print function
*/
void plotMagnitudeErrors(double *t, double *PosErr, double *VelErr){

}