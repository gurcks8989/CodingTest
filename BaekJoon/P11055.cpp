/*
가장 큰 증가 부분 수열
문제 출처: https://www.acmicpc.net/problem/11055

수열 A가 주어졌을 때, 그 수열의 증가 부분 수열 중에서 합이 가장 큰 것을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {1, 100, 2, 50, 60, 3, 5, 6, 7, 8} 인 
경우에 합이 가장 큰 증가 부분 수열은 A = {1, 2, 50, 60} 이고, 합은 113이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)

출력
첫째 줄에 수열 A의 합이 가장 큰 증가 부분 수열의 합을 출력한다.

예제 입력 1 
10
1 100 2 50 60 3 5 6 7 8
예제 출력 1 
113
*/

#include <iostream>
#include <vector>
#define MAX 1000 + 1

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int A[MAX] = {0, }, dp[MAX] = {0, } ;
    vector<int> v ;
    int N, cnt = 0, maximum ;
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
    maximum = A[N] ;
    vector<pair<int, int>> ascendingSeq(1, make_pair(A[N], N)) ;
    // first is sequence of sum & second is index of minimum order
    for(int i = N -1 ; 0 < i ; i--){
        vector<pair<int, int>> subSeq ;
        bool isInsert = false ;
        for(auto seq : ascendingSeq){
            if(dp[i] < dp[seq.second] && A[i] < A[seq.second]){
                subSeq.push_back(make_pair(seq.first + A[i], i)) ;
                maximum = max(maximum, seq.first + A[i]) ;
                isInsert = false ;
            }
            else{
                maximum = max(maximum, A[i]) ;
                isInsert = true ;
            }
        }
        if(isInsert)
            subSeq.push_back(make_pair(A[i], i)) ; 
        int temp = 0 ;
        for(auto seq : subSeq)
            if(i == seq.second)
                temp = max(temp, seq.first) ;
        for(vector<pair<int, int>>::iterator iter = subSeq.begin() ; iter != subSeq.end() ; iter++){
            if(i == iter->second && iter->first < temp){
                subSeq.erase(iter) ;
                iter -= 1 ;
            }
        }
        ascendingSeq.insert(ascendingSeq.end(), subSeq.begin(), subSeq.end());
    }
    cout << maximum << "\n" ;
    return 0 ;
}