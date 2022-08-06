/*
수 정렬하기 3
문제 출처: https://www.acmicpc.net/problem/10989

N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 10,000,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 수가 주어진다. 이 수는 10,000보다 작거나 같은 자연수이다.

출력
첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.

예제 입력 1 
10
5
2
3
1
4
2
3
5
1
7
예제 출력 1 
1
1
2
2
3
3
4
5
5
7
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N ;
    cin >> N ;
    map<int, int> m ;
    for(int i = 0 ; i < N ; i++){
        int temp ;
        cin >> temp ;
        if(m.find(temp) != m.end())
            m[temp] += 1 ;
        else
            m[temp] = 1 ;
    }
    vector<pair<int, int>> list(m.begin(), m.end()) ;

    sort(list.begin(), list.end()) ;
    for(int i = 0 ; i < list.size() ; i++)
        for(int j = 0 ; j < list[i].second ; j++)
            cout << list[i].first << "\n" ;
    return 0 ;
}