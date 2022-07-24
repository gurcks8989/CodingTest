/*
방 번호
문제 출처:https://www.acmicpc.net/problem/1475

다솜이는 은진이의 옆집에 새로 이사왔다. 
다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.
다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다.
한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 
다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
(6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)

입력
첫째 줄에 다솜이의 방 번호 N이 주어진다. N은 1,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 필요한 세트의 개수를 출력한다.

예제 1 입출력 
9999        2
예제 2 입출력 
122         2
예제 3 입출력
12635       1
예제 4 입출력 
888888      6
*/

#include <iostream>
#include <cstring>

using namespace std ; 

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    string N ;
    int nums_cnt[9] = {0, } ;
    cin >> N ;
    
    for(auto n : N){
		if (n == '9') n = '6';
        nums_cnt[n-'0'] += 1;
    }
    nums_cnt[6] = nums_cnt[6]/2 + nums_cnt[6]%2 ;

    int maximum = 0 ;
    for(auto i : nums_cnt){
        maximum = max(i, maximum) ;
    }

    cout << maximum << endl ;
    return  0 ;
}