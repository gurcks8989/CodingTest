//P_1461

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
문제
도서관
세준이는 도서관에서 일한다. 도서관의 개방시간이 끝나서 세준이는 사람들이 마구 놓은 책을 다시 가져다 놓아야 한다. 
세준이는 현재 0에 있고, 사람들이 마구 놓은 책도 전부 0에 있다. 각 책들의 원래 위치가 주어질 때, 
책을 모두 제자리에 놔둘 때 드는 최소 걸음 수를 계산하는 프로그램을 작성하시오. 
세준이는 한 걸음에 좌표 1칸씩 가며, 책의 원래 위치는 정수 좌표이다. 책을 모두 제자리에 놔둔 후에는 다시 0으로 돌아올 필요는 없다. 
그리고 세준이는 한 번에 최대 M권의 책을 들 수 있다.

입력
첫째 줄에 책의 개수 N과, 세준이가 한 번에 들 수 있는 책의 개수 M이 주어진다. 
둘째 줄에는 책의 위치가 주어진다. N은 10,000보다 작거나 같은 자연수이고, 
M은 10,000보다 작거나 같다. 책의 위치는 0이 아니며, 그 절댓값이 10,000보다 작거나 같다.

출력
첫째 줄에 정답을 출력한다.

예제 입력 1 
7 2
-37 2 -6 -39 -29 11 -28
예제 출력 1 
131
(39 + 29 + 11 + 6 ) *2 - 39

*/

int main(){
    ios::sync_with_stdio();
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N, M, temp ;
    cin >> N >> M;

    vector <int> set ;

    for(int n = 0; n < N; n ++){
        cin >> temp ;
        set.push_back(temp) ;
    }

    sort(set.begin(), set.end()) ;

    int sum = 0, index = 0;

    if(abs(set[N-1]) < abs(set[0]))
        sum -= abs(set[0]) ;
    else
        sum -= abs(set[N-1]) ;

    for(int i = 0 ; i < N; i++){
        if(i%M == 0){
            sum += abs(2 * set[i]) ;
            if(set[i+M] > 0){
                index = i + 1 ;
                break ;
            }
        }
    }
    for(int i = index ; i < N; i++){
        if(set[i] > 0){
            index = i;
            break ;
        }
    }
    int size = N-1-index ;
    for(int i = size ; i >= 0; i--){
        if(i%M == size%M){
            sum += abs(2 * set[i+index]) ;
            if(set[i+index-M] < 0){
                break ;
            }
        }
    }

    printf("%d\n", sum) ;
    return 0 ;
}