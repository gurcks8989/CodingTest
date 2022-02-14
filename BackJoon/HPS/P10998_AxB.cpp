/*
A×B 
문제 출처:https://www.acmicpc.net/problem/10998

두 정수 A와 B를 입력받은 다음, A×B를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. (0 < A, B < 10)

출력
첫째 줄에 A×B를 출력한다.

예제 입력 1 
1 2
예제 출력 1 
2
예제 입력 2 
3 4
예제 출력 2 
12
*/

#include <iostream>

using namespace std;

int main(){
    
    int a, b ;
    
    do{
        cin >> a;
    }while(a <= 0) ;

    do{
        cin >> b;
    }while(10 <= b) ;
  
    int mul = a * b ;
    
    cout << mul << endl;
    
    return 0 ;
}