/*
별 찍기 - 1
문제 출처: https://www.acmicpc.net/problem/2438

첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

입력
첫째 줄에 N(1 ≤ N ≤ 100)이 주어진다.

출력
첫째 줄부터 N번째 줄까지 차례대로 별을 출력한다.

예제 입력 1 
5
예제 출력 1 
*
**
***
****
*****
*/

#include <iostream>
#include <vector>

using namespace std;

void printStar(int n){
    if(n==0)
        return ;
    cout << "*" ;
    printStar(n-1) ;
}

int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    ios::sync_with_stdio(false) ;
    
    int N ; 
    cin >> N ;
    for(int i = 1 ; i <= N ; i++){
        printStar(i) ;
        cout << "\n" ;
    }
    return 0 ;
}