/*
좋은 날 싫은 날 스페셜 저지
문제 출처:https://www.acmicpc.net/problem/17211 

지은이가 건국한 나라인 유애나에 살고 있는 재현이는 너무 단순한 나머지 매일이 기분이 좋은 날, 
기분이 싫은 날 두가지로 나누어진다. 어느 날 지은이는 재현이에 대한 놀라운 사실을 발견했다! 
재현이의 오늘의 기분이 내일의 기분에 영향을 준다는 것이었다. 
문득 지은이는 N일 뒤의 재현이의 기분이 어떻게 될지 궁금하였다. 
지은이를 위해 N일 뒤 재현이의 기분이 어떨지 알려주는 프로그램을 만들어보자.

입력
첫째 줄에 정수 N(1 ≤ N ≤ 100)과 현재 재현이의 기분(좋은 날 0, 싫은 날 1)이 주어진다.
둘째 줄에 차례대로 재현이가 기분이 좋은 날의 다음 날도 기분이 좋은 날일 확률, 다음 날은 기분이 싫은 날일 확률, 기분이 싫은 날의 다음 날이 기분이 좋은 날일 확률, 
다음 날도 기분이 싫은 날일 확률이 주어진다. 확률은 소수점 둘째자리까지 주어진다.

출력
N일 뒤의 재현이의 기분이 좋은 날일 확률과 싫은 날일 확률에 
1,000을 곱해 소수점 첫째자리에서 반올림한 수를 차례대로 출력한다. 절대 오차는 100까지 허용한다.

예제 입력 1 
2 1
0.70 0.30 0.50 0.50
예제 출력 1 
600
400
*/

#include <iostream>
#define GOOD 0
#define BAD 1

using namespace std ; 

double rate[2][2] ;
double good[2][101] ;
double bad[2][101] ;

double days_later_good(short days, bool curr_day_type){
    if(days == 0){
        if(!curr_day_type)
            return 1.0 ;
        else
            return 0.0 ;
    }
    double & temp = good[curr_day_type][days] ;
    if(temp != -1.0) return temp ;
    return temp = rate[curr_day_type][GOOD] * days_later_good(days-1, GOOD) + rate[curr_day_type][BAD] * days_later_good(days-1, BAD);
}

double days_later_bad(short days, bool curr_day_type){
    if(days == 0){
        if(curr_day_type)
            return 1.0 ;
        else
            return 0.0 ;
    }
    double & temp = bad[curr_day_type][days] ;
    if(temp != -1.0) return temp ;
    return temp = rate[curr_day_type][GOOD] * days_later_bad(days-1, GOOD) + rate[curr_day_type][BAD] * days_later_bad(days-1, BAD);
}

int main(){
    short N ;
    bool is_bad_day ;
    cin >> N >> is_bad_day ;
    for (int i = 0; i < 2; i++){
        cin >> rate[i][GOOD] >> rate[i][BAD] ;
        for (int j = 0; j < 101; j++){
            good[i][j] = -1;
            bad[i][j] = -1;
        }
    }
    cout << int(days_later_good(N, is_bad_day) * 1000) << endl << int(days_later_bad(N, is_bad_day) * 1000) << endl ;
    return 0 ; 
}