#include "stdio.h"

int main(){

    int A = 3;
    int B;
    int *P = &A;
    int *Q = P;
    int *R = &B;

    printf("Enter value:");
    scanf("%d",R);
    printf("A:%d \t B:%d\n", A, B);
    printf("*P:%d \t *Q:%d \t *R:%d\n", *P, *Q, *R);

    Q = &B;
    if (P == Q)
    printf("1\n");
    if (Q == R)
    printf("2\n");
    if (*P == *Q)
    printf("3\n");
    if (*Q == *R)
    printf("4\n");
    if (*P == *R)
    printf("5\n");


    return 0 ;
}