/*
히스토그램에서 가장 큰 직사각형 
문제 출처: https://www.acmicpc.net/problem/6549

히스토그램은 직사각형 여러 개가 아래쪽으로 정렬되어 있는 도형이다. 
각 직사각형은 같은 너비를 가지고 있지만, 높이는 서로 다를 수도 있다. 
예를 들어, 왼쪽 그림은 높이가 2, 1, 4, 5, 1, 3, 3이고 너비가 1인 직사각형으로 이루어진 히스토그램이다.

히스토그램에서 가장 넓이가 큰 직사각형을 구하는 프로그램을 작성하시오.

입력
입력은 테스트 케이스 여러 개로 이루어져 있다. 
각 테스트 케이스는 한 줄로 이루어져 있고, 직사각형의 수 n이 가장 처음으로 주어진다. (1 ≤ n ≤ 100,000) 
그 다음 n개의 정수 h1, ..., hn (0 ≤ hi ≤ 1,000,000,000)가 주어진다. 
이 숫자들은 히스토그램에 있는 직사각형의 높이이며, 왼쪽부터 오른쪽까지 순서대로 주어진다. 
모든 직사각형의 너비는 1이고, 입력의 마지막 줄에는 0이 하나 주어진다.

출력
각 테스트 케이스에 대해서, 히스토그램에서 가장 넓이가 큰 직사각형의 넓이를 출력한다.

예제 입력 1 
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
0
예제 출력 1 
8
4000
*/

#include <iostream>
#include <vector>
#define ll long long
#define N_SIZE 100000 + 1

using namespace std ;

void init(vector<int> & tree, vector<int> & arr, int start, int end, int node){
    if(start == end){
        tree[node] = start ;
        return ;
    }
    int mid = (start + end) / 2 ;
    init(tree, arr, start, mid, node * 2) ;
    init(tree, arr, mid + 1, end, node * 2 + 1) ;

    tree[node] = (arr[tree[node * 2]] <= arr[tree[node * 2 + 1]]) ? tree[node * 2] : tree[node * 2 + 1] ;
}

int getMinHeight(vector<int> & tree, vector<int> & arr, int start, int end, int node, int left, int right) {
    if (right < start || end < left)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    
    int mid = (start + end) / 2;
    int m1 = getMinHeight(tree, arr, start, mid, node * 2, left, right);
    int m2 = getMinHeight(tree, arr, mid + 1, end, node * 2 + 1, left, right);
    
    if (m1 == -1)
        return m2;
    else if (m2 == -1)
        return m1;
    else{
        if (arr[m1] <= arr[m2])
            return m1;
        else
            return m2;
    }
}

ll getMax(vector<int> & tree, vector<int> & arr, int start, int end) {
    int m = getMinHeight(tree, arr, 1, arr.size(), 1, start, end);
    ll area = (ll)(end - start + 1) * (ll) arr[m];

    if (start <= m - 1)
    area = max(area, getMax(tree, arr, start, m - 1)) ;
    if (m + 1 <= end) 
    area = max(area, getMax(tree, arr, m + 1, end)) ;

    return area;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int n ;
    while(true){
        cin >> n ;
        if(n == 0)
            break ;
        vector<int> arr(n), tree(N_SIZE * 4) ;
        for(int i = 1 ; i <= n ; i++)
            cin >> arr[i] ;
        init(tree, arr, 1, n, 1) ;        
        cout << getMax(tree, arr, 1, n) << "\n" ;
        arr.clear() ;   tree.clear() ;
    }
    return 0 ;
}