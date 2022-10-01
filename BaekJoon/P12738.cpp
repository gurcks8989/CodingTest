/*
가장 긴 증가하는 부분 수열 3
문제 출처: https://www.acmicpc.net/problem/12738

수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.

예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 
가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.

입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.

둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

출력
첫째 줄에 수열 A의 가장 긴 증가하는 부분 수열의 길이를 출력한다.

예제 입력 1 
6
10 20 10 30 20 50
예제 출력 1 
4
*/

#include <iostream>
#define MAX 1000000 + 1

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int sequences[MAX] = {0, } ;
    int N, index = 0 ;
    cin >> N ;
    for(int i = 1 ; i <= N ; i++){
        int temp ;
        cin >> temp ;
        auto pos = lower_bound(sequences + 1, sequences + index + 1, temp) ;
        *pos = temp ;
        if(pos == sequences + index + 1)
            index += 1 ;
    }
    cout << index << "\n" ;
    return 0 ;
}