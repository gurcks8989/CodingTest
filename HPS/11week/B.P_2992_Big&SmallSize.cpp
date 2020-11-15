//P_16112

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제
정수 X가 주어졌을 때, X와 구성이 같으면서 X보다 큰 수 중 가장 작은 수를 출력한다.
수의 구성이 같다는 말은, 수를 이루고 있는 각 자리수가 같다는 뜻이다. 
예를 들어, 123과 321은 수의 구성이 같다. 하지만, 123과 432는 구성이 같지 않다.

입력
첫째 줄에 X가 주어진다. (1 ≤ X ≤ 999999) X는 0으로 시작하지 않는다.

출력
첫째 줄에 결과를 출력한다. 만약 그러한 숫자가 없는 경우에는 0을 출력한다.

예제 입력 1 
156
예제 출력 1 
165

*/



// find_Sum_Experience_Point

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    int X;
    cin >> X ;
    vector <int> v;
    int Y = X ;

    while(Y >= 10){
        v.push_back(Y % 10) ;
        Y /= 10 ;
    }
    v.push_back(Y) ;

    for(int i = 0 ; i < v.size(); i++)
        printf("%d\n", v[i]);

    return 0;
}