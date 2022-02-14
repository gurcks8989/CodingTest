/*
사칙연산 
문제 출처:https://www.acmicpc.net/problem/10869

두 자연수 A와 B가 주어진다. 
이때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

입력
두 자연수 A와 B가 주어진다. (1 ≤ A, B ≤ 10,000)

출력
첫째 줄에 A+B, 둘째 줄에 A-B, 셋째 줄에 A*B, 넷째 줄에 A/B, 다섯째 줄에 A%B를 출력한다.

예제 입력 1 
7 3
예제 출력 1 
10
4
21
2
1
*/

#include <iostream>

#define range(x) (1 <= x && x <= 10000)

using namespace std;

void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void dvi(int a, int b);
void reamin(int a, int b);

int main(){
    
    int a, b ;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;
  
    add(a, b) ;
    sub(a, b) ;
    mul(a, b) ;
    dvi(a, b) ;
    reamin(a, b) ;
    
    return 0 ;
}


void add(int a, int b){

    int sum = a + b ;

    cout << sum << endl;

}

void sub(int a, int b){

    int sub = a - b ;

    cout << sub << endl;
}

void mul(int a, int b){

    int mul = a * b ;
    
    cout << mul << endl;
}

void dvi(int a, int b){
    
    int dvi = a / b ;
    
    cout << dvi << endl;

}

void reamin(int a, int b){

    int remain = a % b;

    cout << remain << endl;

}