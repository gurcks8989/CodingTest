/*
쉬운 계단 수
문제 출처: https://www.acmicpc.net/problem/10844

45656이란 수를 보자.

이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.

N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 0으로 시작하는 수는 계단수가 아니다.

입력
첫째 줄에 N이 주어진다. N은 1보다 크거나 같고, 100보다 작거나 같은 자연수이다.

출력
첫째 줄에 정답을 1,000,000,000으로 나눈 나머지를 출력한다.

예제 입력 1 
1
예제 출력 1 
9
예제 입력 2 
2
예제 출력 2 
17
*/

#include <iostream>
#define MAX 100 + 1
#define MOD 1000000000
#define ll long long 

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ll dp[MAX][11] ;
    int N ;
    cin >> N ;
    for(int i = 1 ; i <= 9 ; i++)
        dp[1][i] = 1 ;
    for(int i = 2 ; i <= N ; i++){
        dp[i][0] = dp[i-1][1] ;
        dp[i-1][10] = 0 ;
        for(int j = 1 ; j <= 9 ; j++)
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD ;
    }
    ll sum = 0 ;
    for(int i = 0 ; i < 10 ; i++)
        sum += dp[N][i] ;
    cout << sum % MOD << "\n" ;
    return 0 ;
}