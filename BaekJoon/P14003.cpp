/*
가장 긴 증가하는 부분 수열 5
문제 출처: https://www.acmicpc.net/problem/14003

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 
 가장 긴 증가하는 부분 수열은 A = {10, 20, 10, 30, 20, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

둘째 줄에는 정답이 될 수 있는 가장 긴 증가하는 부분 수열을 출력한다.

예제 입력 1 
6
10 20 10 30 20 50
예제 출력 1 
4
10 20 30 50
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000 + 1

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    vector<int> A(MAX, 0), dp(MAX, 0) ;
    vector<int> v, answer ;
    int N, cnt = 0 ;
    cin >> N ;
    for(int i = 1 ; i <= N ; i++)
        cin >> A[i] ;
    v.push_back(A[1]) ;
    for(int i = 2 ; i <= N ; i++){
        if(v[cnt] < A[i]){
            v.push_back(A[i]) ;
            cnt += 1 ;
            dp[i] = cnt ;
        }
        else{
            auto pos = lower_bound(v.begin(), v.end(), A[i]) ;
            *pos = A[i] ;
            dp[i] = pos - v.begin() ;
        }
    }
    int size = cnt ;
    for(int i = N ; 0 < i ; i--){
        if(size == dp[i]){
            answer.push_back(A[i]) ;
            size -= 1 ;
        }
    }
    reverse(answer.begin(), answer.end()) ;
    cout << answer.size() << "\n" ;
    for(auto ele : answer)
        cout << ele << " " ;
    return 0 ; 
}