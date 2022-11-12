/*
종이의 개수
문제 출처: https://www.acmicpc.net/problem/1780

N×N크기의 행렬로 표현되는 종이가 있다. 
종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다. 
우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.

만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
(1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서 (1)의 과정을 반복한다.
이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수,
 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

입력
첫째 줄에 N(1 ≤ N ≤ 37, N은 3k 꼴)이 주어진다. 다음 N개의 줄에는 N개의 정수로 행렬이 주어진다.

출력
첫째 줄에 -1로만 채워진 종이의 개수를,
 둘째 줄에 0으로만 채워진 종이의 개수를,
 셋째 줄에 1로만 채워진 종이의 개수를 출력한다.

예제 입력 1 
9
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
0 0 0 1 1 1 -1 -1 -1
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0
0 1 -1 0 1 -1 0 1 -1
0 -1 1 0 1 -1 0 1 -1
0 1 -1 1 0 -1 0 1 -1
예제 출력 1 
10
12
11
*/

#include <iostream>
#define RANGE 2187

using namespace std ;

short paper[RANGE][RANGE] ;
int N = 0 ;
int counts[3] ;
// 0 is -1, 1 is 0, 2 is 1 
bool checkCut(int standard, pair<int, int> row, pair<int, int> col){
    for(int i = row.first ; i <= row.second ; i++){
        for(int j = col.first ; j <= col.second ; j++){
            if(standard != paper[i][j])
                return false ;
        }
    }
    return true ;
}

void dividePaper(pair<int, int> row, pair<int, int> col){
    int standard = paper[row.first][col.first] ;
    if(checkCut(standard, row, col)){
        standard != 1 ? (standard != 0 ? counts[0]++ : counts[1]++ ) : counts[2]++ ;
        return ;
    }
    int n = (row.second - row.first) / 3 ;
    pair<int, int> rowT = make_pair(row.first, row.first + n ) ;
    pair<int, int> rowC = make_pair(row.first + n + 1, row.second - n - 1) ;
    pair<int, int> rowB = make_pair(row.second - n, row.second) ;
    pair<int, int> colL = make_pair(col.first, col.first + n) ;
    pair<int, int> colC = make_pair(col.first + n + 1, col.second - n - 1) ;
    pair<int, int> colR = make_pair(col.second - n, col.second) ;
    dividePaper(rowT, colL) ;   dividePaper(rowT, colC) ;   dividePaper(rowT, colR) ;
    dividePaper(rowC, colL) ;   dividePaper(rowC, colC) ;   dividePaper(rowC, colR) ;
    dividePaper(rowB, colL) ;   dividePaper(rowB, colC) ;   dividePaper(rowB, colR) ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++)
        for(int j = 0 ; j < N ; j++)
            cin >> paper[i][j] ;
    pair<int, int> init(0, N-1);
    dividePaper(init, init) ;
    for(int i = 0 ; i < 3 ; i++)
        cout << counts[i] << "\n" ;
    return 0 ;
}