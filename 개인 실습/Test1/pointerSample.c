#include "stdio.h"

void changeVar(float *cvar) {
  *cvar = *cvar + 10.0;
}


float *findMax(float A[], int N) {
  int I;
  float *theMax = &(A[0]);

  for (I = 1; I < N; I++)
    if (A[I] > *theMax) theMax = &(A[I]);

  return theMax;
}

int  main() {

  int V = 101;
  float p = (float) V ;
  float *P = (float *) &V; 

  printf("%d\n", V) ;
  printf("%.1f", p) ;
  printf("%.1f", *P) ;
  return 0 ;
}