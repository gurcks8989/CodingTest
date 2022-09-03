/*
이항 계수 2
문제 출처: https://www.acmicpc.net/problem/11051

자연수 N과 정수 K가 주어졌을 때 이항 계수 
binom{N}{K}를 10,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ K ≤ N)

출력
 
binom{N}{K}를 10,007로 나눈 나머지를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10
*/

#include <iostream>
#define RANGE 1001
#define MOD 10007

using namespace std ;

int dp[RANGE][RANGE] ;

int combination(int n, int k){
    int temp = 0 ;
    if(dp[n][k])
        return dp[n][k] ;
    if(n < 0 || n < k || k < 0)
        return 0 ;
    else if(n == k || k == 0)
        temp = 1 ;
    else if(k == 1 || k == n)
        temp = n ;
    else
        temp = combination(n-1, k-1) + combination(n-1, k) ;
    dp[n][k] = temp % MOD ;
    return dp[n][k] ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N, K ;
    cin >> N >> K ;
    cout << combination(N, K) << "\n" ;
    return 0 ;
}