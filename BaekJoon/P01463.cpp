/*
1로 만들기
문제 출처: https://www.acmicpc.net/problem/1463

정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

입력
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

출력
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.

예제 입력 1 
2
예제 출력 1 
1
예제 입력 2 
10
예제 출력 2 
3
*/

#include <iostream>

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int X, cnt = 0 ;
    cin >> X ;
    while(X != 1){
        if(X % 3 == 0)
            X /= 3 ;
        else if(X % 2 == 0)
            X /= 2 ;
        else
            X -= 1 ;
        cnt += 1 ;
    }
    cout << cnt << "\n" ;
    return 0 ;
}