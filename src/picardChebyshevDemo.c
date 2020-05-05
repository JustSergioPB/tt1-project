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

   double r0Pow2[3];
   arrayPow(3, 2, r0, r0Pow2);

   double sum1 = sumArrayElements(3, r0Pow2);
   double a = sqrt(sum1);
   double param = sqrt(mu/a);
   double v0[3] = {0, param, 0};

   double v0Pow2[3];
   arrayPow(3, 2, v0, v0Pow2);
   double sum2 = sumArrayElements(3, v0Pow2);
   double vMag = sqrt(sum2);

   double p = 2*M_PI*sqrt(pow(a, 3)/mu);
   double tSpan[2] = {0, p*2};

   int n = 50;
   double noisePrct = 0.25;
   
   double tau[n+1];
   for(int i = 50, j = 0; i >= 0; i--){
      tau[j] = cos(j*M_PI/n);
      j++;  
   }

   double omega1 = (tSpan[1]+tSpan[0])/2;
   double omega2 = (tSpan[1]-tSpan[0])/2;
   
   double tauTimesOmega2[n+1];
   multiplyArrayByScalar(n+1, tau, omega2, tauTimesOmega2);
   double t[n+1];
   addScalarToArray(n+1, tauTimesOmega2, omega1, t);

   double **r0Matr = (double **) calloc(3, sizeof(double *));
   double **v0Matr = (double **) calloc(3, sizeof(double *));

   double errorTolerance = 1e-6;  

   for(int j = 0; j < n+1; j++){
      for(int i = 0; i < 3; i++){
         r0Matr[i][j] = r0[i];
         v0Matr[i][j] = v0[i];
      }
   }

   double **rFinMatr;
   double **vFinMatr;

   keplerUniversal(3, n+1, r0Matr, v0Matr, t, mu, &rFinMatr, &vFinMatr);

   double **r_guess = (double **) calloc(3, sizeof(double *));
   double **v_guess = (double **) calloc(3, sizeof(double *));

   for(int j = 0; j < n+1; j++){
      for(int i = 0; i < 3; i++){
         r_guess[i][j] = rFinMatr[i][j] + rand()*a*noisePrct*2 - a*noisePrct;
         v_guess[i][j] = vFinMatr[i][j] + rand()*vMag*noisePrct*2 - vMag*noisePrct;
      }
   }

   double **x_guess = (double **) calloc(2*(n+1), sizeof(double *));
   double **r_guessTransposed;
   double **v_guessTransposed;
   transpose(3, n+1, r_guess, &r_guessTransposed);
   transpose(3, n+1, v_guess, &v_guessTransposed);

   // TODO assign x_guess values
   

   vmpcm(n+1, 3, tau, &x_guess, omega1, omega2, errorTolerance);
   // TODO recheck this
   double **rvPCM;

   double PCMPosMag[3];
   double APosMag[3];
   double PCMVelMag[3];
   double AVelMag[3];
   double PosErr[3];
   double VelErr[3];
   double **rFinMatrTransposed;
   double **vFinMatrTransposed;
   transpose(3, n+1, rFinMatr, &rFinMatrTransposed);
   transpose(3, n+1, vFinMatr, &vFinMatrTransposed);

   for(int i = 0; i < 3; i++){
      PCMPosMag[i] = 0.0;
      for(int j = 0; j < 3; j++ ){
         PCMPosMag[i] += pow(x_guess[i][j], 2);
      }
      PCMPosMag[i] = sqrt(PCMPosMag[i]);
   }

   for(int i = 0; i < 3; i++){
      PCMVelMag[i] = 0.0;
      for(int j = 3; j < n+1; j++ ){
         PCMVelMag[i] += pow(x_guess[i][j], 2);
      }
      PCMVelMag[i] = sqrt(PCMVelMag[i]);
   }

   // @TODO must recheck stop condition
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

   // @TODO must recheck stop condition
   for(int i= 0; i < n+1; i++){
      PosErr[i] = fabs(PCMPosMag[i] - APosMag[i]);
      VelErr[i] = fabs(PCMVelMag[i] - AVelMag[i]);
   }

   plotPositionAndVelocity(rvPCM, rFinMatr, vFinMatr, vMag, a, t, x_guess);
   plotMagnitudeErrors(t, PosErr, VelErr);

   freeMatrix(3, rFinMatr);
   freeMatrix(3, vFinMatr);
   freeMatrix(3, r0Matr);
   freeMatrix(3, v0Matr);
   freeMatrix(3, r_guess);
   freeMatrix(3, v_guess);
   freeMatrix(3, r_guessTransposed);
   freeMatrix(3, v_guessTransposed);
   freeMatrix(2*(n+1), x_guess);
}


void twoBodyForceModel(int rows, int columns, double *t, double **posvel, double mu, double ***f){
   
   double **eta = (double **) calloc(rows, sizeof(double *));
   double rMag[rows];
   double nuR3[rows];

   for(int i = 0; i < rows; i++){
      rMag[i] = 0.0; 
      
      for(int j = 0; j < 3; j++){
         rMag[i] += pow(posvel[i][j], 2);
      }
      rMag[i] = sqrt(rMag[i]);

      nuR3[i] = -mu/pow(rMag[i], 3); 
      
      eta[i][1] = posvel[i][4];
      eta[i][2] = posvel[i][5];
      eta[i][3] = posvel[i][6];
      eta[i][4] = nuR3[i]*posvel[i][1];
      eta[i][5] = nuR3[i]*posvel[i][2];
      eta[i][6] = nuR3[i]*posvel[i][3];
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