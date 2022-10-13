/*
나머지 합
문제 출처: https://www.acmicpc.net/problem/10986

수 N개 A1, A2, ..., AN이 주어진다. 
이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.

즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.

입력
첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)

둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)

출력
첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.

예제 입력 1 
5 3
1 2 3 1 2
예제 출력 1 
7
*/

#include <iostream>
#define NMAX 1000000 + 1
#define MMAX 1000
#define ll long long 

using namespace std ;

int A[NMAX] = {0, } ;
ll remain[MMAX] ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N, M ;
    ll answer = 0 ;
    cin >> N >> M ;
    for(int i = 0 ; i < M ; i++)
        remain[i] = 0 ;
    for(int i = 1 ; i <= N ; i++){
        int temp ;
        cin >> temp ;
        A[i] = (A[i-1] + temp) % M ;
        remain[A[i]] += 1 ;
    }
    answer += remain[0] ;
    for(int i = 0 ; i < M ; i++)
        answer += remain[i] * (remain[i]-1) / 2 ;
    cout << answer << "\n" ;
    return 0 ;
}