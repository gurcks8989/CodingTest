/*
체스판 다시 칠하기 2
문제 출처: https://www.acmicpc.net/problem/25682

지민이는 자신의 저택에서 MN개의 단위 정사각형으로 나누어져 있는 M×N 크기의 보드를 찾았다. 
어떤 정사각형은 검은색으로 칠해져 있고, 나머지는 흰색으로 칠해져 있다. 
지민이는 이 보드를 잘라서 K×K 크기의 체스판으로 만들려고 한다.

체스판은 검은색과 흰색이 번갈아서 칠해져 있어야 한다. 
구체적으로, 각 칸이 검은색과 흰색 중 하나로 색칠되어 있고,
 변을 공유하는 두 개의 사각형은 다른 색으로 칠해져 있어야 한다. 
 따라서 이 정의를 따르면 체스판을 색칠하는 경우는 두 가지뿐이다. 
 하나는 맨 왼쪽 위 칸이 흰색인 경우, 하나는 검은색인 경우이다.

보드가 체스판처럼 칠해져 있다는 보장이 없어서, 
지민이는 K×K 크기의 체스판으로 잘라낸 후에 몇 개의 정사각형을 다시 칠해야겠다고 생각했다. 
당연히 K×K 크기는 아무데서나 골라도 된다. 
지민이가 다시 칠해야 하는 정사각형의 최소 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N, M, K가 주어진다. 
둘째 줄부터 N개의 줄에는 보드의 각 행의 상태가 주어진다. 
B는 검은색이며, W는 흰색이다.

출력
첫째 줄에 지민이가 잘라낸 K×K 보드를 체스판으로 만들기 위해 다시 칠해야 하는 정사각형 개수의 최솟값을 출력한다.

제한
1 ≤ N, M ≤ 2000
1 ≤ K ≤ min(N, M)
예제 입력 1 
4 4 3
BBBB
BBBB
BBBW
BBWB
예제 출력 1 
2
예제 입력 2 
8 8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
예제 출력 2 
1
예제 입력 3 
10 13 10
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB
예제 출력 3 
30
예제 입력 4 
9 23 9
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBBBBBBBBB
BBBBBBBBBBBBBBBWWWWWWWW
예제 출력 4 
40
*/

#include <iostream>
#include <vector>
#define MAX 2000 + 1
#define ll long long 

using namespace std ;

ll maximum = 0, minmum = 1000000000 ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    vector<vector<bool>> board(MAX, vector<bool>(MAX, false)) ;
    vector<vector<int>> checkCnts(MAX, vector<int>(MAX, 0)) ;
    vector<vector<ll>> subSum(MAX, vector<ll>(MAX, 0)) ;
    int N, M, K ;
    char c ;
    cin >> N >> M >> K ;
    for(int i = 1 ; i <= N ; i++){
        for(int j = 1 ; j <= M ; j++){
            cin >> c ;
            board[i][j] = (c == 'W') ;
        }
    }

    bool prev = board[1][1] ;
    for(int i = 1 ; i <= N ; i++){
        int cnt = 0 ;
        for(int j = 1 ; j <= M ; j++){
            if(board[i][j] != prev)
                cnt += 1 ;
            checkCnts[i][j] = cnt ;
            subSum[i][j] += checkCnts[i][j] + subSum[i-1][j] ;
            prev = !prev ;
        }
        if(M%2 == 0)
            prev = !prev ;
    }

    for(int i = 1 ; i <= N - K + 1 ; i++){
        for(int j = 1 ; j <= M - K + 1 ; j++){
            ll sum = subSum[i+K-1][j+K-1] - subSum[i-1][j+K-1] - subSum[i+K-1][j-1] + subSum[i-1][j-1] ;
            maximum = max(maximum, sum) ;
            minmum = min(minmum, sum) ;
        }
    }
    cout << min(minmum, K*K-maximum) << "\n" ;
    return 0 ;
}