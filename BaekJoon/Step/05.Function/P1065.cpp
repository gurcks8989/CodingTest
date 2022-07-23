/*
한수
문제 출처: https://www.acmicpc.net/problem/1065

어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 
N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오. 

입력
첫째 줄에 1,000보다 작거나 같은 자연수 N이 주어진다.

출력
첫째 줄에 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력한다.

예제 입력 1 
110
예제 출력 1 
99
예제 입력 2 
1
예제 출력 2 
1
예제 입력 3 
210
예제 출력 3 
105
예제 입력 4 
1000
예제 출력 4 
144
예제 입력 5 
500
예제 출력 5 
119
*/

#include <iostream>
#include <vector>

using namespace std ; 

int main(){
    int N, answer = 0 ; 
    cin >> N ;
    for(int i = 1 ; i <= N ; i++){
        int j = i ;
        vector<int> v ;
        while (0 < j){
            v.push_back(j % 10) ;
            j /= 10 ;
        }
        if(2 < v.size()){
            int a1 = *(v.end()-1) ;
            int prev = a1, d = 0 ;
            bool isFirst = true, isExist = true ;
            // arithmetic progression: a_n = a_1 + (n-1)d
            for(vector<int>::iterator iter = v.end() - 2; iter != v.begin() - 1 ; iter--){
                if(isFirst){
                    isFirst = false ;
                    d = *iter - prev ;
                }
                else{
                    if(*iter - prev != d){
                        isExist = false ;
                        break ;
                    }
                }
                prev = *iter ;
            }
            if(isExist)
                answer += 1 ;
        }
        else   
            answer += 1 ;        
    }
    cout << answer << "\n" ;
    return 0 ;
}