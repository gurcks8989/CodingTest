/*
나머지
문제 출처: https://www.acmicpc.net/problem/10430

(A+B)%C는 ((A%C) + (B%C))%C 와 같을까?
(A×B)%C는 ((A%C) × (B%C))%C 와 같을까?

세 수 A, B, C가 주어졌을 때, 위의 네 가지 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)

출력
첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 
셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.

예제 입력 1 
5 8 4
예제 출력 1 
1
1
0
0
*/

#include <iostream>
#include <vector>

#define range(x) (2 <= x && x <= 10000)

using namespace std;

void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void dvi(int a, int b);
void reamin(int a, int b);

int main(){
    
    int a, b, c;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;

    do{
        cin >> c;
    }while(!range(c)) ;
    
    vector<int> th(4);

    th[0] = (a+b)%c;
    th[1] = ((a%c) + (b%c))%c;
    th[2] = (a*b)%c;
    th[3] = ((a%c) * (b%c))%c;

    for(int i = 0 ; i < th.size(); i++)
        cout << th[i] << endl;     
    
    return 0 ;
}

//첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.