/*
쿼드트리
문제 출처: https://www.acmicpc.net/problem/1992

흑백 영상을 압축하여 표현하는 데이터 구조로 쿼드 트리(Quad Tree)라는 방법이 있다. 
흰 점을 나타내는 0과 검은 점을 나타내는 1로만 이루어진 영상(2차원 배열)에서 같은 숫자의 점들이 한 곳에 많이 몰려있으면, 
쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.

주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 된다. 
만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고,
 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래, 이렇게 4개의 영상으로 나누어 압축하게 되며, 
 이 4개의 영역을 압축한 결과를 차례대로 괄호 안에 묶어서 표현한다

위 그림에서 왼쪽의 영상은 오른쪽의 배열과 같이 숫자로 주어지며, 
 이 영상을 쿼드 트리 구조를 이용하여 압축하면 "(0(0011)(0(0111)01)1)"로 표현된다.  
N ×N 크기의 영상이 주어질 때, 이 영상을 압축한 결과를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 영상의 크기를 나타내는 숫자 N 이 주어진다. 
N 은 언제나 2의 제곱수로 주어지며, 1 ≤ N ≤ 64의 범위를 가진다. 
두 번째 줄부터는 길이 N의 문자열이 N개 들어온다. 
각 문자열은 0 또는 1의 숫자로 이루어져 있으며, 영상의 각 점들을 나타낸다.

출력
영상을 압축한 결과를 출력한다.

예제 입력 1 
8
11110000
11110000
00011100
00011100
11110000
11110000
11110011
11110011
예제 출력 1 
((110(0101))(0010)1(0001))
*/

#include <iostream>
#define RANGE 64

using namespace std ;

bool matrix[RANGE][RANGE] ;

bool checkCut(bool isBlack, pair<int, int> row, pair<int, int> col){
    for(int i = row.first ; i <= row.second ; i++){
        for(int j = col.first ; j <= col.second ; j++){
            if(isBlack != matrix[i][j])
                return false ;
        }
    }
    return true ;
}

void compressionMatrix(pair<int, int> row, pair<int, int> col){ 
    bool isBlack = matrix[row.first][col.first] ;
    if(checkCut(isBlack, row, col)){
        cout << (isBlack ? "1" : "0") ;
        return ;
    }
    cout << "(" ;
    int n = (row.second - row.first) / 2 ;
    pair<int, int> rowT = make_pair(row.first, row.first + n) ;
    pair<int, int> rowB = make_pair(row.second - n, row.second) ;
    pair<int, int> colL = make_pair(col.first, col.first + n) ;
    pair<int, int> colR = make_pair(col.second - n, col.second) ;
    compressionMatrix(rowT, colL) ;   compressionMatrix(rowT, colR) ;
    compressionMatrix(rowB, colL) ;   compressionMatrix(rowB, colR) ;
    cout << ")" ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int N ; 
    cin >> N ;
    for(int i = 0 ; i < N ; i++){
        string line ;
        cin >> line ;
        for(int j = 0 ; j < N ; j++){
            matrix[i][j] = (line[j] == '1') ;
        }
    }
    pair<int, int> init(0, N-1) ;
    compressionMatrix(init, init) ;
    return 0 ;
}