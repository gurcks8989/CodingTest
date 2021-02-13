#include "stdio.h"

int main(){

    int V = 7;
    int *P = &V ;
    printf("%d\n", *P) ;
    int A[5];

    for(int i = 0 ; i < 5 ; i ++)
        A[i] = i ;

    P = &(A[2]);

    printf("%d\n", *P) ;

    printf("%d\n ", V) ;
 
    return 0 ;
}