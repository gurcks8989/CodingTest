/*
구간 합 구하기
문제 출처: https://www.acmicpc.net/problem/2042

어떤 N개의 수가 주어져 있다. 
그런데 중간에 수의 변경이 빈번히 일어나고 그 중간에 어떤 부분의 합을 구하려 한다. 
만약에 1,2,3,4,5 라는 수가 있고,
 3번째 수를 6으로 바꾸고 2번째부터 5번째까지 합을 구하라고 한다면 17을 출력하면 되는 것이다. 
그리고 그 상태에서 다섯 번째 수를 2로 바꾸고 3번째부터 5번째까지 합을 구하라고 한다면 12가 될 것이다.

입력
첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000,000)과 M(1 ≤ M ≤ 10,000), K(1 ≤ K ≤ 10,000) 가 주어진다. 
M은 수의 변경이 일어나는 횟수이고, K는 구간의 합을 구하는 횟수이다. 
그리고 둘째 줄부터 N+1번째 줄까지 N개의 수가 주어진다. 
그리고 N+2번째 줄부터 N+M+K+1번째 줄까지 세 개의 정수 a, b, c가 주어지는데, 
 a가 1인 경우 b(1 ≤ b ≤ N)번째 수를 c로 바꾸고
 a가 2인 경우에는 b(1 ≤ b ≤ N)번째 수부터 c(b ≤ c ≤ N)번째 수까지의 합을 구하여 출력하면 된다.

입력으로 주어지는 모든 수는 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

출력
첫째 줄부터 K줄에 걸쳐 구한 구간의 합을 출력한다. 단, 정답은 -263보다 크거나 같고, 263-1보다 작거나 같은 정수이다.

예제 입력 1 
5 2 2
1
2
3
4
5
1 3 6
2 2 5
1 5 2
2 3 5
예제 출력 1 
17
12
*/

#include <iostream>
#include <vector>
#define ll long long
#define N_SIZE 1000000
using namespace std ;

vector<ll> tree(N_SIZE * 4, 0), arr(N_SIZE, 0) ;

ll init(int start, int end, int node){
    if(tree[node] != 0)
        return tree[node] ;
    if(start == end)
        return tree[node] = arr[start] ;
    int mid = (start + end) / 2 ;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1) ;
}

ll sum(int start, int end, int node, int left, int right) {
	if(left > end || right < start) 
        return 0;
	if(left <= start && end <= right) 
        return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, ll dif) {
	if(index < start || index > end) return;
	tree[node] += dif;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid + 1, end, node * 2 + 1, index, dif);
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N, M, K ;
    cin >> N >> M >> K ;
    for(int i = 1 ; i <= N ; i++)
        cin >> arr[i] ;
    init(1, N, 1) ;
    for(int i = 1 ; i <= M + K ; i++){
        int a, b ;
        ll c ;
        cin >> a >> b >> c ;
        if(a == 1){
            ll dif = c - arr[b] ;
            arr[b] = c ;
            update(1, N, 1, b, dif) ;
        }
        else if(a == 2)
            cout << sum(1, N, 1, b, (int) c) << "\n" ;
    }
    return 0 ;
}