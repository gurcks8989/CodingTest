/*
이항 계수 3
문제 출처: https://www.acmicpc.net/problem/11401

자연수 N과 정수 K가 주어졌을 때 이항 계수 binom{N}{K}를 1,000,000,007로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N과 K가 주어진다. (1 ≤ N ≤ 4,000,000, 0 ≤ K ≤ N)

출력
 
binom{N}{K}를 1,000,000,007로 나눈 나머지를 출력한다.

예제 입력 1 
5 2
예제 출력 1 
10
*/

#include <iostream>
#include <vector>
#define ll long long
#define MOD 1000000007

using namespace std ;

ll pow(ll a, ll b) {
	if (b == 0) return 1;
	ll temp = pow(a, b/2);
    if(b % 2 == 1)
        return (temp * ((temp*(a % MOD)) % MOD)) % MOD ;
    return (temp * temp) % MOD ;
}

int main() {
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    vector<ll> factorials(2, 1) ;
    int N, K;
	cin >> N >> K;
	for (int i = 2; i <= N; i++) 
		factorials.push_back((*(factorials.end()-1) * i) % MOD) ;
	ll A = factorials[N], B = ((factorials[K] % MOD) * (factorials[N-K] % MOD)) % MOD ;
    //A = n!, B = k!(n-k)!
    cout << (A * pow(B, MOD-2)) % MOD << "\n" ;
	return 0;
}