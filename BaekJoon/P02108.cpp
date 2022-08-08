/*
통계학
문제 출처: https://www.acmicpc.net/problem/2108

수를 처리하는 것은 통계학에서 상당히 중요한 일이다. 
통계학에서 N개의 수를 대표하는 기본 통계값에는 다음과 같은 것들이 있다. 단, N은 홀수라고 가정하자.

산술평균 : N개의 수들의 합을 N으로 나눈 값
중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
최빈값 : N개의 수들 중 가장 많이 나타나는 값
범위 : N개의 수들 중 최댓값과 최솟값의 차이
N개의 수가 주어졌을 때, 네 가지 기본 통계값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 500,000)이 주어진다. 단, N은 홀수이다. 
그 다음 N개의 줄에는 정수들이 주어진다. 입력되는 정수의 절댓값은 4,000을 넘지 않는다.

출력
첫째 줄에는 산술평균을 출력한다. 소수점 이하 첫째 자리에서 반올림한 값을 출력한다.

둘째 줄에는 중앙값을 출력한다.

셋째 줄에는 최빈값을 출력한다. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.

넷째 줄에는 범위를 출력한다.

예제 입력 1 
5
1
3
8
-2
2
예제 출력 1 
2
2
1
10
예제 입력 2 
1
4000
예제 출력 2 
4000
4000
4000
0
예제 입력 3 
5
-1
-2
-3
-1
-2
예제 출력 3 
-2
-2
-1
2
예제 입력 4 
3
0
0
-1
예제 출력 4 
0
0
0
1
(0 + 0 + (-1)) / 3 = -0.333333... 이고 이를 첫째 자리에서 반올림하면 0이다. 
-0으로 출력하면 안된다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define ABS 4000

using namespace std ;

bool orderByCount(pair<int, int> & a, pair<int, int> & b){
    if(a.second == b.second)
        return a.first < b.first ;
    return a.second > b.second ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
	int N, min = ABS + 1, max = -ABS - 1;
    long long sum = 0 ;
    cin >> N ;
    vector<int> nums(N) ;
    map<int, int> m ;
    for(int i = 0 ; i < N ; i++){
        cin >> nums[i] ;
        if(m.find(nums[i]) != m.end())
            m[nums[i]] += 1 ;
        else
            m[nums[i]] = 1 ;    
        sum += nums[i] ;
        if(nums[i] < min)
            min = nums[i] ;
        if(max < nums[i])
            max = nums[i] ;
    }
    vector<pair<int, int>> pairs(m.begin(), m.end()) ;
    sort(nums.begin(), nums.end()) ;
    sort(pairs.begin(), pairs.end(), orderByCount) ;
    bool positive = true ;
    if(sum/(double)N <= -1)
        positive = false ;
    if((int)(sum/(double)N + 0.5) == (int)(sum/(double)N))
        cout << sum / N << "\n" ;
    else{
        if(positive)
            cout << sum / N + 1 << "\n" ;
        else
            cout << sum / N - 1 << "\n" ;
    }
    
    cout << nums[N/2] << "\n" ;

    if(1 < N && pairs[0].second == pairs[1].second)
        cout << pairs[1].first << "\n" ;
    else
        cout << pairs[0].first << "\n" ;

    cout << max - min << "\n" ;
        
    return 0 ;
}