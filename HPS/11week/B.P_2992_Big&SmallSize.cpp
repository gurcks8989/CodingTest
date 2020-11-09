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


int n, k;
//int num[300000] ;

// find_Sum_Experience_Point

int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k ;
    vector<int> v;

    for(int i = 0 ; i < n ; i ++){
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
    }

    // 0번째는 0
    // 1번쨰는 제일 작은 수를 제외한 수의 합
    // 2번째는 제일 작은 수와 두번쨰 수를 제외한 수의 합
    // ... 이러한 것들이 k개 존재

	sort(v.begin(), v.end());

    long long int sum = 0 ;
    int i = 0 ;
    // v.at(j) * i   /(3*10^5*10*8/)
    for(int j = 0 ; j < n ; j ++){
        sum += (long long int)v.at(j) * (long long int)i ;
        if (i < k)
            i++;
    }
    
    printf("%lld\n", sum) ;

    return 0;
}