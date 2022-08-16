/*
직각삼각형 
문제 출처: https://www.acmicpc.net/problem/4153

과거 이집트인들은 각 변들의 길이가 3, 4, 5인 삼각형이 직각 삼각형인것을 알아냈다.
주어진 세변의 길이로 삼각형이 직각인지 아닌지 구분하시오.

입력
입력은 여러개의 테스트케이스로 주어지며 마지막줄에는 0 0 0이 입력된다. 
각 테스트케이스는 모두 30,000보다 작은 양의 정수로 주어지며, 각 입력은 변의 길이를 의미한다.

출력
각 입력에 대해 직각 삼각형이 맞다면 "right", 아니라면 "wrong"을 출력한다.

예제 입력 1 
6 8 10
25 52 60
5 12 13
0 0 0
예제 출력 1 
right
wrong
right
*/

#include <iostream>

using namespace std ;

// a^b
int pow(int a, int b){
    if(b == 0)
    	return 1 ;
	return a * pow(a, b-1) ;
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
	int lines[3] ;
    do{
        int max = -1, index = -1 ;
		for(int i = 0 ; i < 3 ; i++){
        	cin >> lines[i] ;
            if(max < lines[i]){
                max = lines[i] ;
                index = i ;
            } 
        }
        if(lines[0]+lines[1]+lines[2] == 0) 
            break ;
        int a = 0, b = 0 ;
        switch(index){
            case 0 :    a = lines[1] ;  b = lines[2] ;  break ;
            case 1 :    a = lines[0] ;  b = lines[2] ;  break ;
            case 2 :    a = lines[0] ;  b = lines[1] ;  break ;
            default :   break ;
        }
		if(pow(max, 2) == pow(a, 2) + pow(b, 2))
            cout << "right\n" ;
        else
            cout << "wrong\n" ;
    }while(lines[0]+lines[1]+lines[2] != 0) ;

    return 0 ;
}