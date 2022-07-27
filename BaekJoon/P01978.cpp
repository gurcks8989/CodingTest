/*
소수 찾기
문제 출처: https://www.acmicpc.net/problem/1978

주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 
다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.

예제 입력 1 
4
1 3 5 7
예제 출력 1 
3
*/

#include <iostream>
#include <cstring>
#define MAXRANGE 1000

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N, answer = 0 ;
    bool primeNum[MAXRANGE] ;
    memset(primeNum, true, sizeof(primeNum)) ;

    primeNum[0] = false ; primeNum[1] = false ;
    for(int i = 2 ; i <= MAXRANGE ; i++){
        if(primeNum[i]){
            for(int j = 2 ; i * j <= 1000 ; j++){
                primeNum[i * j] = false ;
            }
        }
    }

    cin >> N ;
    for(int i = 0 ; i < N ; i++){
        int temp ;
        cin >> temp ;
        if(primeNum[temp])
            answer += 1 ;
    }   
    cout << answer << "\n" ;
    return 0 ;
}