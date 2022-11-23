/*
K번째 수
문제 출처: https://www.acmicpc.net/problem/1300

세준이는 크기가 N×N인 배열 A를 만들었다. 
배열에 들어있는 수 A[i][j] = i×j 이다. 
이 수를 일차원 배열 B에 넣으면 B의 크기는 N×N이 된다. 
B를 오름차순 정렬했을 때, B[k]를 구해보자.


배열 A와 B의 인덱스는 1부터 시작한다.

입력
첫째 줄에 배열의 크기 N이 주어진다. 
N은 105보다 작거나 같은 자연수이다. 
둘째 줄에 k가 주어진다. 
k는 min(109, N2)보다 작거나 같은 자연수이다.

출력
B[k]를 출력한다.

예제 입력 1 
3
7
예제 출력 1 
6
*/

#include <iostream>
#define ll long long

using namespace std ;

int N ;     ll K ;
int binary_search(int left, int right){
    if(right < left) 
        return left;
    int mid = (left + right) / 2;
    ll cnt = 0 ;

    for(int i = 1 ; i <= N ; i++)
        cnt += (mid/i < N) ? mid/i : N ;
    
    if(cnt < K)
        return binary_search(mid + 1, right);
    return binary_search(left, mid - 1);
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    cin >> N >> K ;
    cout << binary_search(1, K) << "\n" ;
    return 0 ;
}