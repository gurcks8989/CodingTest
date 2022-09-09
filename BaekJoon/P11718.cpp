/*
그대로 출력하기
문제 출처: https://www.acmicpc.net/problem/11718

입력 받은 대로 출력하는 프로그램을 작성하시오.

입력
입력이 주어진다. 입력은 최대 100줄로 이루어져 있고, 알파벳 소문자, 대문자, 공백, 숫자로만 이루어져 있다. 
각 줄은 100글자를 넘지 않으며, 빈 줄은 주어지지 않는다. 또, 각 줄은 공백으로 시작하지 않고, 공백으로 끝나지 않는다.

출력
입력받은 그대로 출력한다.

예제 입력 1 
Hello
Baekjoon
Online Judge
예제 출력 1 
Hello
Baekjoon
Online Judge
*/

#include <iostream>

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    string str ;
    while (!cin.eof()) {    //EOF를 만날때까지 무한 입력
        getline(cin, str) ;
        cout << str << "\n" ;
    }
    return 0 ;
}