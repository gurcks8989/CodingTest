
/*
시험 점수를 입력받아 
90 ~ 100점은 A, 
80 ~ 89점은 B, 
70 ~ 79점은 C, 
60 ~ 69점은 D, 
나머지 점수는 F를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>

#define range(x) (0 <= x && x <= 100)

using namespace std;

void grade(int a);

int main(){
    
    int a ;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    grade(a) ;

    return 0 ;
}

void grade(int a){

    char case_ ;
    enum{Large, Equal, Small} ;

    if(90 <= a)
        case_ = 'A' ; 
    else if(80 <= a)
        case_ = 'B' ;
    else if(70 <= a)
        case_ = 'C' ; 
    else if(60 <= a)
        case_ = 'D' ; 
    else
        case_ = 'F' ; 

    cout << case_ << endl;
}
