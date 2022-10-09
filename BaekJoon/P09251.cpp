/*
LCS
문제 출처: https://www.acmicpc.net/problem/9251

LCS(Longest Common Subsequence, 최장 공통 부분 수열)문제는 두 수열이 주어졌을 때, 
모두의 부분 수열이 되는 수열 중 가장 긴 것을 찾는 문제이다.

예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.

입력
첫째 줄과 둘째 줄에 두 문자열이 주어진다. 
문자열은 알파벳 대문자로만 이루어져 있으며, 최대 1000글자로 이루어져 있다.

출력
첫째 줄에 입력으로 주어진 두 문자열의 LCS의 길이를 출력한다.

예제 입력 1 
ACAYKP
CAPCAK
예제 출력 1 
4
*/

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000 + 1

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    string first, second ;
    vector<vector<int>> dp(MAX, vector<int>(MAX, 0)) ;
    cin >> first >> second ;
    int sizeF = first.size(), sizeS = second.size() ;
    for(int i = 1 ; i <= sizeF ; i++){
        dp[i][0] = 0 ;
        for(int j = 1 ; j <= sizeS ; j++){
            dp[i][j] = max({dp[i][j-1], 
                            dp[i-1][j],
                            dp[i-1][j-1] + (first[i-1] == second[j-1]) 
                           });
        }
    }
    cout << dp[sizeF][sizeS] << "\n" ; 
    return 0 ;
}