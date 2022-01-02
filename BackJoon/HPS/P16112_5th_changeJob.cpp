//P_16112

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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