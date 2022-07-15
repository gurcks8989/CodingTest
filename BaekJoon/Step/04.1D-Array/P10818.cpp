/*
최소, 최대
문제 출처: https://www.acmicpc.net/problem/10818

N개의 정수가 주어진다. 이때, 최솟값과 최댓값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수의 개수 N (1 ≤ N ≤ 1,000,000)이 주어진다. 
둘째 줄에는 N개의 정수를 공백으로 구분해서 주어진다. 
모든 정수는 -1,000,000보다 크거나 같고, 1,000,000보다 작거나 같은 정수이다.

출력
첫째 줄에 주어진 정수 N개의 최솟값과 최댓값을 공백으로 구분해 출력한다.

예제 입력 1 
5
20 10 35 30 7
예제 출력 1 
7 35
*/

#include <iostream>
#define MAXRANGE 1000001
#define MINRANGE -1000001

using namespace std ;

int main(){
    cin.tie(NULL) ;
    cout.tie(NULL) ; 
    ios::sync_with_stdio(false) ;

    int N, min = MAXRANGE, max = MINRANGE;
    cin >> N ;
    
    for(int i = 0 ; i < N ; i++){
        int temp ;
        cin >> temp ;
        if(max < temp)
            max = temp ;
        if(temp < min)
            min = temp ;
    }

    cout << min << " " << max << "\n" ;

    return 0 ;
}