/*
단어 공부
문제 출처:https://www.acmicpc.net/problem/1157

알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오.
단, 대문자와 소문자를 구분하지 않는다.

입력
첫째 줄에 알파벳 대소문자로 이루어진 단어가 주어진다. 주어지는 단어의 길이는 1,000,000을 넘지 않는다.

출력
첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다. 
단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ?를 출력한다.

예제 입력 1     예제 출력 1 
Mississipi      ?

예제 입력 2     예제 출력 2 
zZa             Z

예제 입력 3     예제 출력 3 
z               Z

예제 입력 4     예제 출력 4 
baaa            A
*/

#include <iostream>
#define ALPHABET 26
using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;     cout.tie(NULL) ;
    int cnt[ALPHABET] = {0, }, max = 0, index ;
    bool is_duplication = false ;
    string word ;
    cin >> word ;
    for(auto a : word){
        if('Z' < a) // lowercase
            cnt[a - 'a'] += 1 ;
        else
            cnt[a - 'A'] += 1 ;
    }
    for(int i = 0 ; i < ALPHABET ; i++){
        if(max < cnt[i]){
            index = i ;
            max = cnt[i] ;
            is_duplication = false ;
        }
        else if(max == cnt[i])
            is_duplication = true ;
    }
    char answer = is_duplication ? '?' : 'A' + index ;
    cout << answer << endl ;
    return 0 ;
}