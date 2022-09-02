/*
이항 계수 1
문제 출처: https://www.acmicpc.net/problem/11050

자연수 N과 정수 K가 주어졌을 때 이항 계수 
binom{N}{K}를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 10, 0 ≤ K ≤ N)

출력
 
binom{N}{K}를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10
*/

#include <iostream>

using namespace std ;

int factorial(int n){
    if(n==0)
        return 1 ;
    return n * factorial(n-1) ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N, K ;
    cin >> N >> K ;
    cout << factorial(N) / (factorial(K) * factorial(N-K)) << "\n" ;
    return 0 ;
}