/*
조합 0의 개수
문제 출처: https://www.acmicpc.net/problem/2004
 
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m (0 <= m <= n <= 2,000,000,000, n != 0)이 들어온다.

출력
첫째 줄에 
nCm의 끝자리 0의 개수를 출력한다.

예제 입력 1 
25 12
예제 출력 1 
2
*/

#include <iostream>
#include <algorithm>

using namespace std ;

long getFactor(int n, int divisor){
    int cnt = 0 ;
    for(long i = divisor; i <= n; i *= divisor )
        cnt += n/i;
    return cnt ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    int n, m, cnt2 = 0, cnt5 = 0 ;
    cin >> n >> m ;
    cout << min(getFactor(n, 2) - getFactor(m, 2) - getFactor(n-m, 2), getFactor(n, 5) - getFactor(m, 5) - getFactor(n-m, 5)) << "\n" ;
    return 0 ;
}