

//#define P1 
#define P2
//#define P3


#include <iostream>

using namespace std ;

/*
문제 1: 부피 구하기
1. 부피를 구하는 함수를 정의한다.
- 높이가 주어지지 않는 경우에는 2이라고 가정 한다. - default prameter을 활용한다.
int boxVolume(int length, int width, int height)
Ex)
[3, 5, 5]   15 
[3, 2]      12

2. 부피를 구하는 함수 두개를 정의하고, namespace를 활용하여 두 개의 함수를 구별하여라.
int boxVolume(int length, int width, int height)
float boxVolume(float length, float width, float height)
Ex)
[3, 5, 5]     15 
[3.1, 3.5, 5] 35.7

*/

#ifdef P1

//#define task 
// if you try task #2, undefine task


#ifdef task
int boxVolume(int length, int width, int height = 2)
{
    return length * width * height ;
}

float boxVolume(float length, float width, float height)
{
    return length * width * height ; 
}

#endif

#ifndef task
namespace n_int{
    int boxVolume(int length, int width, int height)
    {
        return length * width * height ;
    }
}

namespace n_float{
    float boxVolume(float length, float width, float height)
    {
        return length * width * height ; 
    }
}
#endif

int main(){
    #ifdef task
    int v1 = boxVolume(3, 5, 5);
    int v2 = boxVolume(3, 2);
    cout << "task1" << endl ;
    cout << "[3, 5, 5]\t" << v1 << endl ;
    cout << "[3, 2]\t\t" << v2 << "\n" << endl ;
    #endif

    #ifndef task
    int v3 = n_int::boxVolume(3, 5, 5) ;
    float v4 = n_float::boxVolume(3.1, 3.5, 5.5) ;
    cout << "task2" << endl ;
    cout << "[3, 5, 5]\t" << v3 << endl ;
    cout << "[3.1, 3.5, 5]\t" << v4 << "\n" << endl ;
    #endif
    
    return 0 ;
}
#endif



/*

문제 2: swap 함수 구현하기
1. 문자, intege형, float type형 swap 함수를 구현하여라.
- 함수이름은 모두 swap으로 한다 (overloading )
2. setw,setf 함수를 활용하여 다음 예시와 같이 화살표가 일자로 출력되게 하여라.

- setw함수는 여백을 설정해 주는 함수이다.
- setf 함수는 오른쪽 혹은 왼쪽 정렬을 설정하는 함수이다. 
- #include <iomanip> 헤더파일을 추가하면 사용할 수있다.

ex)
cout.setf(ios::left); //왼쪽으로 정렬 정렬 
cout<<setw(20)<<a

30 20 -> 20 30
Z A -> A Z
5.555 1. 111 -> 1.111 5.555
*/

#ifdef P2

#include <iomanip>

void swap(char * a, char * b)
{
    char temp = *a ;
    *a = *b ;
    *b = temp ;
}

void swap(int * a, int * b)
{
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void swap(float * a, float * b)
{
    float temp = *a ;
    *a = *b ;
    *b = temp ;
}

int main(){
    cout.setf(ios::left); //왼쪽으로 정렬 정렬 
   
    int x = 30, y = 20 ;
    char z = 'Z', a = 'A';
    float five = 5.555, one = 1.111;
    
    cout << x << " " << y ;
    swap(&x, &y) ;
    cout << setw(7) << " " << "-> " << x << " " << y << endl ;
    
    cout << z << " " << a ;
    swap(&z, &a) ;
    cout << setw(9) << " " << "-> " << z << " " << a << endl ;

    cout << five << " " << one ;
    swap(&five, &one) ;
    cout << " -> " << five << " " << one << endl ;
    
    return 0 ;
}
#endif




/*
문제 3: min-sec
struct min_sec {
    int min;        을 기본 형태로 한
    int sec;        다. 
}

1. 시간의 합을 구하는 함수를 정의한다.

-operator overloading을 활용한다.
*주의: sec의 합이 60 이상이면 min의 값이 1 증가하여야 한다.

min-sec operator+ (min-sec & op1, min-sec &op2)

2. 시간의 차를 구하는 함수를 정의한다. 

-function overloadin을 활용한다.

int diff(min-sec op1, min-sec op2) 
int diff(int sec1, min-sec op2)

3. min-sec type을 출력하는 함수를 정의 한다. 

방법1)operator overloading을 활용한다.
friend ostream & operator<<(ostream & os, min-sec & c) 

방법2)member fuction 을 활용한다.
void showInfo()

4. 스스로 구현하기
bool operator< (min_sec op1, min_sec op2) 
bool operator> (min_sec op1, min_sec op2)
min-sec operator< (min-sec op1, min-sec op2)

void main(){ 
    min_sec a, b,c,d; 
    a.min = 5;
    
    a.sec = 59; 
    b.min = 10; 
    b.sec = 30;
    
    c = a + b;
    d = a - b;
    cout <<"Time1:"<< a;
    cout << "Time2:"<<b;
    cout << "Time1+Time2:" << c; 
    cout << "Time1-Time2:" << d; 
    cout << "(a<b):";

    if (a < b) 
        cout<<"ture"<<endl; 
    else 
        cout << "false" << endl;

    cout << "(a>b)";
    
    if (a > b) 
        cout << "ture" << endl;
    else 
        cout << "false" << endl; }

    <출력화면>
    Time1: 5 min 59 sec 
    Time2: 10 min 30 sec
    
    Time1+Time2 : 16 min 29 sec 
    Time1-Time2 : 271 sec
    Time 1>Time 2: false
    Time 1<Time 2: true

*/

#ifdef P3

struct min_sec {
    int min;        
    int sec;        
} ;

//&가 있고 없고의 차이는 reference의 차이
//shallow copy, deep copy의 차이가 있다
//추가로 point는 8byte, struct의 size의 따라 크기가 달라지는 것과는 다르게 reference는 그 크기가 고정되어 있다.

min_sec operator+ (min_sec & op1, min_sec & op2)
{
    min_sec clock ;

    clock.sec = op1.sec + op2.sec ;
    clock.min = op1.min + op2.min ;

    if(clock.sec / 60 > 1){
        clock.sec %= 60 ;
        clock.min += 1 ;
    }
    
    return clock ;
}

int diff(min_sec op1, min_sec op2) 
{

    return abs(op1.min * 60 + op1.sec - op2.min * 60 - op2.sec) ;
}

int diff(int sec1, min_sec op2)
{
    return abs(sec1 - op2.min * 60 - op2.sec) ;
}

min_sec operator- (min_sec & op1, min_sec &op2)
{
    min_sec clock ;

    int dif = diff(op1, op2) ;

    clock.sec = dif % 60 ;
    clock.min = dif / 60 ;
    
    return clock ;
}

ostream & operator<<(ostream & os, min_sec & c) 
{
    os << " " << c.min << "min " << c.sec << "sec" << endl;

    return os ;
}

bool operator< (min_sec op1, min_sec op2)
{
    if(op1.min < op2.min)
        return true ;
    else if(op1.min > op2.min)
        return false ;
    else if(op1.min == op2.min){
        if(op1.sec < op2.sec)
            return true ;
        else
            return false ;
    }
    return false ;
}

bool operator> (min_sec op1, min_sec op2)
{
    if(op1.min < op2.min)
        return false ;
    else if(op1.min > op2.min)
        return true ;
    else if(op1.min == op2.min){
        if(op1.sec < op2.sec)
            return false ;
        else
            return true ;
    }
    return false ;
}

//min_sec operator< (min_sec op1, min_sec op2)

int main(){ 
    min_sec a, b, c, d; 
    a.min = 5;
    
    a.sec = 59; 
    b.min = 10; 
    b.sec = 30;
    
    c = a + b;
    d = a - b;
    cout << "Time1:" << a;          //Time1: 5 min 59 sec     
    cout << "Time2:" << b;          //Time2: 10 min 30 sec
    cout << "Time1+Time2:" << c;    //Time1+Time2 : 16 min 29 sec 
    cout << "Time1-Time2:" << d;    //Time1-Time2 : 271 sec
    
    cout << "(Time 1<Time 2):";

    if (a < b) 
        cout << "ture" << endl; 
    else 
        cout << "false" << endl;
    //Time 1<Time 2: true
    
    cout << "(Time 1>Time 2)";
    
    if (a > b) 
        cout << "ture" << endl;
    else 
        cout << "false" << endl; 
    //Time 1>Time 2: false

}

#endif