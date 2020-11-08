//P_16112

#include <iostream>

using namespace std;

int n, k;
//int num[300000] ;

// find_Sum_Experience_Point

int compare(const void *a, const void *b) {
	return *(int*)a - *(int *)b; 
}


int main(int argc, const char * argv[]) {
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> k ;
    int num[n] ;

    for(int i = 0 ; i < n ; i ++)
        cin >> num[i] ;

    // 0번째는 0
    // 1번쨰는 제일 작은 수를 제외한 수의 합
    // 2번째는 제일 작은 수와 두번쨰 수를 제외한 수의 합
    // ... 이러한 것들이 k개 존재

	qsort(num,n,sizeof(num[0]),compare);

    int s = 0 ;

    for(int i = 0 ; i < k ; i ++){
        for(int j = i+1 ; j < n ; j ++){
            s += num[j] ;
        }
    }
    
    cout << s << "\n";

    return 0;
}