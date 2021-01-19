

//#define P1 
#define P2


#include <iostream>

using namespace std ;

/*
문제 1: 원의 면적 구하기
1. 원의 개수를 입력받고, 입력받은 개수만큼 반지름의 크기를 입력 받아라.
- 원의 개수에 따라 동적으로 배열을 할당받아야 한다.
class Circle {
int radius; // 원의 반지름 값 public:
void setRadius(int radius); // 반지름을 설정한다.
double getArea(); // 면적을 반환한다. 
};


Ex)
원의 개수 : 3
원 1의 반지름 : 4
원 2의 반지름 : 6
원 3의 반지름 : 8
면적이 100보다 큰 원은 2개입니다.

*/

#ifdef P1

#define MaxSize 3

#include <cmath>

const double PI = 2 * acos(0.0) ;

class Circle {
    public:
        int radius;                 // 원의 반지름 값 public:
        void setRadius(int radius); // 반지름을 설정한다.
        double getArea();           // 면적을 반환한다. 
};

inline double size(int x){
    return 2 * PI * x ;
}

void Circle::setRadius(int radius){
    this->radius = radius ;
}

double Circle::getArea(){
    return this->radius ;
}

int main(){
    
    Circle c[MaxSize] ;
    
    c[0].radius = 4 ;
    c[1].setRadius(6) ;
    c[2].setRadius(8) ;

    cout << "원의 개수 : " << MaxSize << endl ;
    
    int count = 0;

    for(int i = 0 ; i < MaxSize ; i++){
        cout << "원 " << i + 1 << "의 반지름 : " << c[i].radius << endl ;
        // same cout << "원 2의 반지름 : " << c2.getArea() << endl ;
        cout <<size(c[i].getArea())<<endl; 
        if(100 < size(c[i].getArea()))
            count++ ;
    }

    cout << "면적이 100보다 큰 원은 " << count << "개입니다." << endl ;

    return 0 ;
}
#endif


/*

문제 2: 문자열에서 특정 문자 찾기
1. 특정 문자를 찾는 find() 함수를 완성하라.
⁃ 문자열 a에서 문자c를 찾아, 문자c가 있는 공간에 대한 reference를 반환한다.
⁃ 만일 문자 c를 찾을 수 없다면 success 참조 매개변수에 false를 설정한다.

char& find(char a[], char c, bool& success); int main() {
    char s[] = "apple"; 
    bool b = false;
    char& loc = find(s, 'a', b); 
    if(b == false) {
        cout << "a를 발견할 수 없습니다." << endl;
        return 0; 
    }
    loc = 'A';          // 'a' 위치에 ‘A' 기록
    cout << s << endl;  // "apple" 출력 
}
*/

#ifdef P2

char& find(char a[], char c, bool& success)
{
    int len = strlen(a) ;

    for(int i = 0 ; i < len ; i++){
        if(a[i] == c){
            success = true ;
            return a[i] ;
        }
    }
    return a[0];
}

int main() {
    char s[] = "apple"; 
    bool b = false;
    char& loc = find(s, 'a', b); 
    if(b == false) {
        cout << "a를 발견할 수 없습니다." << endl;
        return 0; 
    }
    loc = 'A';          // 'a' 위치에 ‘A' 기록
    cout << s << endl;  // "apple" 출력 

    return 0 ;
}

#endif

