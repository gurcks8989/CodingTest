/*
소수 구하기
문제 출처: https://www.acmicpc.net/problem/1929

M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. 
(1 ≤ M ≤ N ≤ 1,000,000) M이상 N이하의 소수가 하나 이상 있는 입력만 주어진다.

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.

예제 입력 1 
3 16
예제 출력 1 
3
5
7
11
13
*/

#include <iostream>
#include <cstring>
#define MAXRANGE 1000000

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int M, N ;
    bool primeNum[MAXRANGE] ;
    memset(primeNum, true, sizeof(primeNum)) ;

    primeNum[0] = false ; primeNum[1] = false ;
    for(int i = 2 ; i <= MAXRANGE ; i++){
        if(primeNum[i]){
            for(int j = 2 ; i * j <= MAXRANGE ; j++){
                primeNum[i * j] = false ;
            }
        }
    }

    cin >> M >> N ;
    for(int i = M ; i <= N ; i++){
        if(primeNum[i]){
            cout << i << "\n" ;
        }
    }
    return 0 ;
}