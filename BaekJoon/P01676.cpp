/*
팩토리얼 0의 개수
문제 출처: https://www.acmicpc.net/problem/1676

N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.

예제 입력 1 
10
예제 출력 1 
2
예제 입력 2 
3
예제 출력 2 
0
*/

#include <iostream>
#include <algorithm>

using namespace std ;

int getFactorInFactorial(int n, int divisor){
    if(n == 1 || n < divisor)
        return 0;
    int cnt = 0, temp = n ;
    while(temp % divisor == 0){
        cnt += 1 ;
        temp /= divisor ;
    }
    return cnt + getFactorInFactorial(n-1, divisor) ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    short N ;
    cin >> N ;
    cout << min(getFactorInFactorial(N, 2), getFactorInFactorial(N, 5)) << "\n" ;
    return 0 ;
}