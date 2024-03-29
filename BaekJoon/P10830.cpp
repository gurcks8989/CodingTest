/*행렬 제곱
문제 출처: https://www.acmicpc.net/problem/10830

크기가 N*N인 행렬 A가 주어진다. 이때, A의 B제곱을 구하는 프로그램을 작성하시오. 
수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.

예제 입력 1 
2 5
1 2
3 4
예제 출력 1 
69 558
337 406
예제 입력 2 
3 3
1 2 3
4 5 6
7 8 9
예제 출력 2 
468 576 684
62 305 548
656 34 412
예제 입력 3 
5 10
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
1 0 0 0 1
예제 출력 3 
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
512 0 0 0 512
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAT vector<vector<int>>
#define ll long long
#define RANGE 5
#define MOD 1000

using namespace std ;

int N ;
MAT matrix(RANGE, vector<int>(RANGE, 0)) ;

MAT multiply(MAT & a, MAT & b) {
    MAT temp(RANGE, vector<int>(RANGE, 0)) ;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {                
                temp[i][j] += a[i][k] * b[k][j];
                temp[i][j] %= MOD;
            }
        }
    }
    return temp;
}

MAT matrixPow(MAT & matrix, ll b){
    if(b == 1LL)
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
    ll B ;
    cin >> N >> B ;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> matrix[i][j] ;
    MAT answer = matrixPow(matrix, B) ;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++)
            cout << answer[i][j] % MOD << " " ;
        cout << "\n" ;
    }
    return 0 ;
}