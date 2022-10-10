/*
구간 합 구하기 4
문제 출처: https://www.acmicpc.net/problem/11659

수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N과 합을 구해야 하는 횟수 M이 주어진다. 둘째 줄에는 N개의 수가 주어진다. 
수는 1,000보다 작거나 같은 자연수이다. 셋째 줄부터 M개의 줄에는 합을 구해야 하는 구간 i와 j가 주어진다.

출력
총 M개의 줄에 입력으로 주어진 i번째 수부터 j번째 수까지 합을 출력한다.

제한
1 ≤ N ≤ 100,000
1 ≤ M ≤ 100,000
1 ≤ i ≤ j ≤ N
예제 입력 1 
5 3
5 4 3 2 1
1 3
2 4
5 5
예제 출력 1 
12
9
1
*/
#include <iostream>
#define MAX  100000 + 1

using namespace std ;

int subSums[MAX] = {0, } ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N, M ;
    cin >> N >> M ;
    for(int i = 1 ; i <= N ; i++){
        int temp ;
        cin >> temp ;
        subSums[i] = subSums[i-1] + temp ;
    }
    for(int T = 1 ; T <= M ; T++){
        int i, j ;
        cin >> i >> j ;
        cout << subSums[j] - subSums[i-1] << "\n" ;
    }
    return 0 ;
}