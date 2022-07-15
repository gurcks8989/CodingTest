/*
큰 수 A+B
문제 출처: https://www.acmicpc.net/problem/10757

두 정수 A와 B를 입력받은 다음, A+B를 출력하는 프로그램을 작성하시오.
입력
첫째 줄에 A와 B가 주어진다. (0 < A,B < 1010000)
출력
첫째 줄에 A+B를 출력한다.

예제 입력 1 
9223372036854775807 9223372036854775808
예제 출력 1 
18446744073709551615
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

int main(){
    string a, b, answer = "" ; 
    cin >> a >> b ;
    reverse(a.begin(), a.end());    
    reverse(b.begin(), b.end());
    
    int a_size = a.length(), b_size = b.length() ;
    int max_size = max(a_size, b_size) ;
    bool round_up = false ;
    
    for(int i = 0 ; i < max_size ; i++){
        int num = 0 ; 
        if(i < a_size)
            num += a[i] - '0' ;
        if(i < b_size)
            num += b[i] - '0' ;
        
        if(num < 10){
            if(round_up){
                if(num == 9){
                    answer.insert(answer.begin(), '0');
                }
                else{
                    answer.insert(answer.begin(), num + '1');
                    round_up = false ;
                }
            }
            else
                answer.insert(answer.begin(), num + '0');
        }
        else{
            num -= 10 ;
            if(round_up)
                answer.insert(answer.begin(), num + '1');
            else
                answer.insert(answer.begin(), num + '0');
            round_up = true ;
        }
    }
    if(round_up)
        answer.insert(answer.begin(), '1');
    cout << answer << endl ;
    return 0 ;
}