/*
핸드폰 요금
문제 출처:https://www.acmicpc.net/problem/1267

동호는 새악대로 T 통신사의 새 핸드폰 옴머나를 샀다.
새악대로 T 통신사는 동호에게 다음 두 가지 요금제 중 하나를 선택하라고 했다.

영식 요금제는 30초마다 10원씩 청구된다.
이 말은 만약 29초 또는 그 보다 적은 시간 통화를 했으면 10원이 청구된다.
만약 30초부터 59초 사이로 통화를 했으면 20원이 청구된다.

민식 요금제는 60초마다 15원씩 청구된다.
이 말은 만약 59초 또는 그 보다 적은 시간 통화를 했으면 15원이 청구된다.
만약 60초부터 119초 사이로 통화를 했으면 30원이 청구된다.

동호가 저번 달에 새악대로 T 통신사를 이용할 때 통화 시간 목록이 주어지면
어느 요금제를 사용 하는 것이 저렴한지 출력하는 프로그램을 작성하시오.

입력
동호가 저번 달에 이용한 통화의 개수 N이 주어진다. 
N은 20보다 작거나 같은 자연수이다. 둘째 줄에 통화 시간 N개가 주어진다. 
통화 시간은 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 싼 요금제의 이름을 출력한다. 그 후에 공백을 사이에 두고 요금이 몇 원 나오는지 출력한다. 
만약 두 요금제의 요금이 모두 같으면 영식을 먼저 쓰고 민식을 그 다음에 쓴다.

영식은 Y로, 민식은 M으로 출력한다.

예제 입력 1     예제 출력 1 
3               M 45
40 40 40 
----
영식: 20 + 20 + 20 = 60
민식: 15 + 15 + 15 = 45

예제 입력 2     예제 출력 2
3               Y M 90
61 61 61

예제 입력 3     예제 출력 3
2               Y 40
61 10

영식: 30 + 10 = 40
민식: 30 + 15 = 45

예제 입력 4     예제 출력 4
2               Y M 60
60 65

영식: 30 + 30 = 60
민식: 30 + 30 = 60
*/
#include <iostream>
#define Y_FEE 10
#define M_FEE 15

using namespace std ; 

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;
    
    int N, time, Y_total_fee = 0, M_total_fee = 0 ;
    cin >> N ;

    for(int i = 0 ; i < N ; i++){
        cin >> time ;
        Y_total_fee += (time/30+1)*Y_FEE ;
        M_total_fee += (time/60+1)*M_FEE ;
    }
    if(Y_total_fee == M_total_fee)
        cout << "Y M " << Y_total_fee << endl ;
    else if(Y_total_fee < M_total_fee)
        cout << "Y " << Y_total_fee << endl ;
    else
        cout << "M " << M_total_fee << endl ;
    return  0 ;
}