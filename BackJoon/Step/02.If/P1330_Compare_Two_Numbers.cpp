/*
두 수 비교하기
문제 출처:https://www.acmicpc.net/problem/1330

두 정수 A와 B가 주어졌을 때, A와 B를 비교하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A와 B는 공백 한 칸으로 구분되어져 있다.

출력
첫째 줄에 다음 세 가지 중 하나를 출력한다.

A가 B보다 큰 경우에는 '>'를 출력한다.
A가 B보다 작은 경우에는 '<'를 출력한다.
A와 B가 같은 경우에는 '=='를 출력한다.
제한
-10,000 ≤ A, B ≤ 10,000
예제 입력 1 
1 2
예제 출력 1 
<
예제 입력 2 
10 2
예제 출력 2 
>
예제 입력 3 
5 5
예제 출력 3 
==
*/

#include <iostream>

#define range(x) (-10000 <= x && x <= 10000)

using namespace std;

void compare(int a, int b);

int main(){
    
    int a, b, c;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;

    compare(a, b) ;
        
    return 0 ;
}

void compare(int a, int b){

    int case_ = -1;
    enum{Large, Equal, Small} ;

    if(a > b)
        case_ = Large ; 
    else if(a == b)
        case_ = Equal ; 
    else//(a < b)
        case_ = Small ; 

    switch (case_)
    {
    case Large:
        cout << ">" << endl;
        break;
    case Equal:
        cout << "==" << endl;
        break;
    case Small:
        cout << "<" << endl;
        break;
    default:
        break;
    }
    
}
