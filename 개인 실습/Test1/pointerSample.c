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

    int *P = &V;  /* P points to int V */

    int **Q = &P;  /* Q points to int pointer P */

    printf("%d %d %d\n",V,*P,**Q); /* prints 101 3 times */

    return 0 ;
}