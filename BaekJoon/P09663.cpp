/*
N-Queen
문제 출처: https://www.acmicpc.net/problem/9663

N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

예제 입력 1 
8
예제 출력 1 
92
*/

#include <iostream>
#include <cstring>
#include <vector>
#define MAX 15

using namespace std ;

int col[MAX+1] ;
int N, answer = 0 ;


bool promising (int i){
    int k = 1 ;
    bool flag = true ;
    if(col[i] != 0)
        while(k < i && flag){
            if(col[k] != 0)
                if(col[i] == col[k] || ((col[k] < col[i]) ? col[i]-col[k] : col[k]-col[i]) == i - k)
                    flag = false ;
            k += 1 ;
        }
    return flag ;
}

void nQueens (int i){
    if(promising(i)){
        if(i == N)
            answer += 1 ;
        else
            for(int j = 1 ; j <= N ; j++){
                col[i+1] = j ;
                nQueens(i+1, col) ;
            }
    }
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    memset(col, 0, sizeof(int) * (N + 1)) ;
    cin >> N ;
    nQueens(0) ;
    cout << answer << "\n" ;
    return 0 ;
}