/*
We love kriii 
문제 출처:https://www.acmicpc.net/problem/10718

ACM-ICPC 인터넷 예선, Regional, 그리고 World Finals까지 이미 2회씩 진출해버린 
kriii는 미련을 버리지 못하고 왠지 모르게 올해에도 파주 World Finals 준비 캠프에 참여했다.

대회를 뜰 줄 모르는 지박령 kriii를 위해서 격려의 문구를 출력해주자.

입력
본 문제는 입력이 없다.

출력
두 줄에 걸쳐 "강한친구 대한육군"을 한 줄에 한 번씩 출력한다.

예제 입력 1 
예제 출력 1 
강한친구 대한육군
강한친구 대한육군
*/

#include <iostream>

using namespace std ;

void stack(int n) ;

int main(){

    stack(2) ;    

    return 0 ;
}

void stack(int n){
    
    for(int i = 0 ; i < n ; i ++)
        cout << "강한친구 대한육군" << endl ;
    
    return ;
}