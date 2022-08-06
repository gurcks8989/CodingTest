/*
수 정렬하기
문제 출처: https://www.acmicpc.net/problem/2751

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)이 주어진다. 둘째 줄부터 N개의 줄에는 수 주어진다. 
이 수는 절댓값이 1,000,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

예제 입력 1 
5
5
2
3
4
1
예제 출력 1 
1
2
3
4
5
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N ;
    cin >> N ;
    vector<int> list(N) ;
    for(int i = 0 ; i < N ; i++)
        cin >> list[i] ;
    sort(list.begin(), list.end()) ;
    for(int i = 0 ; i < N ; i++)
        cout << list[i] << "\n" ;
    return 0 ;
}