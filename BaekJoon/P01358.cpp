/*
하키
문제 출처: https://www.acmicpc.net/problem/1358

지난주에, 민식주식회사는 IIHF(International Ice Hockey Federation)로부터 긴급한 전화를 받았다.

IIHF는 같은 팀이 링크안에 너무 많으면 알람이 울리는 시스템을 설치해달라고 요청했다.
시스템은 다음과 같이 3개의 부분으로 이루어진다.

디지털카메라가 링크의 사진을 매 1초마다 찍는다.
디지털카메라가 찍은 사진에서 각 선수의 위치를 뽑아낸다.
하키 링크 안에 같은 팀 선수가 총 몇 명인지 계산한다.
하키 링크는 (X, Y)가 가장 왼쪽 아래 모서리인 W * H 크기의 직사각형과,
반지름이 H/2이면서 중심이 (X, Y+R), (X+W, Y+R)에 있는 두 개의 원으로 이루어져 있다. 아래 그림을 참고한다.

선수들의 위치가 주어질 때, 링크 안 또는 경계에 있는 선수가 총 몇 명인지 구하는 프로그램을 작성하시오.



입력
첫째 줄에 수 W H X Y P가 주어진다. P는 선수의 수이다. W와 H는 100보다 작거나 같은 자연수이고, H는 짝수이다. 
X와 Y는 절댓값이 100보다 작거나 같은 정수이다. 
P는 최대 50인 자연수이다. 
둘째 줄부터 P개의 줄에 각 선수들의 x좌표와 y좌표가 주어진다. 
이 좌표는 절댓값이 300보다 작거나 같은 정수이다.

출력
첫째 줄에 링크 안에 있는 선수의 수를 출력한다.

예제 입력 1 
20 10 5 0 3
15 5
1 5
1 1
예제 출력 1 
2
예제 입력 2 
20 10 0 0 14
-5 5
-4 2
-4 8
-3 1
-3 9
0 0
0 10
20 0
20 10
23 1
23 9
24 2
24 8
25 5
예제 출력 2 
14
예제 입력 3 
52 84 -44 66 10
26 118
-33 106
-49 128
40 114
-10 101
47 85
25 142
-16 140
-82 126
7 145
예제 출력 3 
8
예제 입력 4 
24 100 -62 71 8
-63 109
-26 164
-9 91
-113 80
-124 75
-95 140
-89 116
-55 113
예제 출력 4 
6
*/

#include <iostream>

using namespace std ;

int squared(int n){
    return n * n ;
}

bool range(int a, int b, int c){
    return a <= b && b <= c ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int W, H, X, Y, P, answer = 0 ;
    cin >> W >> H >> X >> Y >> P ;
    for(int i = 0 ; i < P ; i++){
        pair<int, int> player ;
        cin >> player.first >> player.second ;
        if(squared(X-player.first) + squared(Y+H/2-player.second) <= squared(H/2) || 
        (range(X, player.first, X+W) && range(Y, player.second, Y+H)) ||
        squared(X+W-player.first) + squared(Y+H/2-player.second) <= squared(H/2))
            answer += 1 ; 
    }
    cout << answer << "\n" ;
    return 0 ;
}