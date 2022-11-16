/*
피보나치 수 6
문제 춣처: https://www.acmicpc.net/problem/11444

피보나치 수는 0과 1로 시작한다. 
0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 
그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n ≥ 2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 1,000,000,007으로 나눈 나머지를 출력한다.

예제 입력 1 
1000
예제 출력 1 
517691607
*/

#include <iostream>
#include <vector>
#define ll long long
#define MAT vector<vector<ll>>
#define RANGE 2
#define MOD 1000000007

using namespace std ;

MAT multiply(MAT & a, MAT & b) {
    MAT temp(RANGE, vector<ll>(RANGE, 0)) ;
    for(int i = 0; i < RANGE; i++) {
        for(int j = 0; j < RANGE; j++) {
            for(int k = 0; k < RANGE; k++) {                
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= MOD;
            }
        }
    }
    return temp;
}

MAT matrixPow(MAT & matrix, ll b){
    if(b <= 1LL)
        return matrix ; 
    MAT temp = matrixPow(matrix, b/2);
    temp = multiply(temp, temp) ;
    if(b % 2LL == 1LL)
        return multiply(temp, matrix) ;
    return temp ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    MAT matrix = {{1, 1}, {1, 0}} ;
    ll n ;
    cin >> n ;
    MAT answer = matrixPow(matrix, n-1) ;
    cout << answer[0][0] << "\n" ;
    return 0 ;
}