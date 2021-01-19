

//#define P1 
//#define P2
//#define P3
#define P4


#include <iostream>

using namespace std ;

/*
문제 1: 계산기 만들기
1. 계산기 기능의 Calculator 클래스를 정의하라.
⁃ 덧셈, 뺄셈, 곱셈 그리고 나눗셈의 기능을 하는 함수를 구현해야 한다. 
⁃ 연산을 할 때마다 어떠한 연산을 몇 번 수행했는지 기록되어야 한다.

int main(void)
{
    Calculator cal;
    cal.Init(); // 초기화
    cout<<“3.2 + 2.4 = “ <<cal.Add(3.2, 2.4)<<endl; 
    cout<<”3.5 / 1.7 = “ <<cal.Div(3.5, 1.7)<<endl; 
    cout<<“2.2 – 1.5 = “<<cal.Min(2.2, 1.5)<<endl; 
    cout<<“4.9 / 1.2 = “<<cal.Div(4.9, 1.2)<<endl; 
    Cal.ShowOpCount();
    return 0;
}
 
<실행 결과>
3.2 + 2.4 = 5.6
3.5 / 1.7 = 2.05882
2.2 – 1.5 = 0.7
4.9 / 1.2 = 4.08333
덧셈: 1 뺄셈: 1 곱셈: 0 나눗셈: 2

*/

#ifdef P1

class Calculator 
{   
    private:
        int add, sub, mul, div ;

    public:
        void Init(void){
            add = 0 ;
            sub = 0 ;
            mul = 0 ;
            div = 0 ;
        }

        double Add(double a, double b) ;
        double Min(double a, double b) ;
        double Mul(double a, double b) ;
        double Div(double a, double b) ;

        void ShowOpCount(void);
};


double Calculator::Add(double a, double b){
    add += 1 ;
    return a + b ;
}

double Calculator::Min(double a, double b){
    sub += 1 ;
    return a - b ;
}

double Calculator::Mul(double a, double b){
    mul += 1 ;
    return a * b ;
}

double Calculator::Div(double a, double b){
    div += 1 ;
    return a / b ;
}

void Calculator::ShowOpCount(void)
{
    cout << "덧셈: " << add << " " ;
    cout << "뺄셈: " << sub << " " ;
    cout << "곱셈: " << mul << " " ;
    cout << "나눗셈: " << div << endl ;
}

int main(void)
{
    Calculator cal;
    cal.Init(); // 초기화
    cout<<"3.2 + 2.4 = " <<cal.Add(3.2, 2.4)<<endl; 
    cout<<"3.5 / 1.7 = " <<cal.Div(3.5, 1.7)<<endl; 
    cout<<"2.2 – 1.5 = "<<cal.Min(2.2, 1.5)<<endl; 
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl; 
    cal.ShowOpCount();
    return 0;
}
#endif



/*
문제 2: 점 만들기
1. Point class를 제작한다.
- 사용자로부터 x, y의 좌표를 입력 받는 함수를 구현해야한다.
- 이때 입력 받은 좌표가 음수라면 오류 메세지를 출력해야한다.
- 이미 저장된 x, y 값을 바꾸는 함수는 bool형으로 선언한다.
- 이때 사용자가 입력한 값이 음수라면 오류메세지와 함께 false를 리턴, 아니라면 true를 리턴하여야 한다.

예시)
class Point{ 
    private:
        intx; //x좌표
        inty; //y좌표 
    public:
        void initMembers(int xpos, int ypos); // x좌표와 y좌표 값 입력 받는 함수 
        int GetX(); // x좌표 반환
        int GetY(); // y좌표 반환
        bool SetX(int xpos); // x값 변경 (음수 체크 필요)
        bool SetY(int ypos); // y값 변경 (음수 체크 필요) 
};
*/


class Point{ 
    private:
        int x; //x좌표
        int y; //y좌표 
    public:
        Point(){
            x = 0 ;
            y = 0 ;
        }
        Point(int xpos, int ypos){
            x = xpos ;
            y = ypos ;
        }
        void initMembers(int xpos, int ypos); // x좌표와 y좌표 값 입력 받는 함수 
        int GetX(); // x좌표 반환
        int GetY(); // y좌표 반환
        bool SetX(int xpos); // x값 변경 (음수 체크 필요)
        bool SetY(int ypos); // y값 변경 (음수 체크 필요)

        friend ostream & operator<<(ostream &os, Point p) ;
        friend Point Add_point(Point &ul, Point &lr) ; 
};

void Point::initMembers(int xpos, int ypos) // x좌표와 y좌표 값 입력 받는 함수 
{
    x = xpos ;
    y = ypos ;
}

int Point::GetX() // x좌표 반환
{
    return x ;
}

int Point::GetY() // y좌표 반환
{
    return y ;
}

bool Point::SetX(int xpos) // x값 변경 (음수 체크 필요)
{
    if(xpos < 0){
       //cout << xpos << "은 음수값입니다. 값 변환이 이루어지지 않았습니다." << endl ;
        return false ;
    }

    x = xpos ;
    //cout << "성공입니다. 정상적으로 " << x << "로 값 변환되었습니다." << endl ;
    return true ;
}

bool Point::SetY(int ypos) // y값 변경 (음수 체크 필요) 
{
    if(ypos < 0){
        //cout << ypos << "은 음수값입니다. 값 변환이 이루어지지 않았습니다." << endl ;
        return false ;
    }
    
    y = ypos ;
    //cout << "성공입니다. 정상적으로 " << y << "로 값 변환되었습니다." << endl ;
    return true ;
}

#ifdef P2

int main(){
    Point p ;
    int x, y ;
    cin >> x >> y ;
    
    p.initMembers(x, y) ;
    cout << "초기 점의 좌표 : (" << p.GetX() << ", " << p.GetY() << ")" << "\n" << endl ;
    
    cout << "x 좌표를 -1로 변경하기" << p.SetX(-1) << endl ;
    cout << "x 좌표 : " << p.GetX() << "\n" << endl ;
    
    cout << "y 좌표를 3으로 변경하기" << p.SetY(3) << endl ;
    cout << "y 좌표 : " << p.GetY() << "\n" << endl ;

    cout << "변경된 점의 좌표 : (" << p.GetX() << ", " << p.GetY() << ")" << "\n" << endl ;
    
        
    return 0 ;
}
#endif

/*
문제 3: 직사각형 만들기
1. Rectangle class를 제작한다.
- 앞서 구현했던 Point class를 사용하여 왼쪽 상단의 좌표와, 오른쪽 하단 의 좌표를 입력 받는 함수를 구현해야한다.
- 이때 입력 받은 좌표로 직사각형이 만들어지지 않으면 오류 메세지를 출력해야한다. (좌표 값 비교가 필요함)
- 직사각형 좌측 상단의 좌표와, 우측 하단의 좌표를 출력하는 함수를 구현해야한다.
예시)
class Rectangle{ private:
Point upLeft;
Point lowRight; public:
void initMembers(Point &ul, Point &lr);
void ShowRecInfo(); };
*/

class Rectangle{ 
    private:
        Point upLeft;
        Point lowRight; 
    public:
        Rectangle(){
            upLeft.initMembers(0, 0) ;
            lowRight.initMembers(0, 0) ;
        }
        Rectangle(Point ul, Point lr){
            upLeft = ul ;
            lowRight = lr ;
        }
        
        void initMembers(Point &ul, Point &lr);
        void showRectInfo(); 
        friend ostream & operator<<(ostream &os, Rectangle R) ;
};

void Rectangle::initMembers(Point &ul, Point &lr)
{
    bool tf = false ;
    if(lr.GetX() <= ul.GetX()){
        cout << "x값에 오류가 있습니다." << endl ;
        tf = true ;
    }
    if(ul.GetY() <= lr.GetY()){
        cout << "y값에 오류가 있습니다." << endl ;
        tf = true ; 
    }

    if(tf)
        return ;

    upLeft = ul ;
    lowRight = lr ;
    cout << "Rectangle을 생성할 수 있습니다." << endl ;
}

void Rectangle::showRectInfo()
{
    cout << "좌상단의 좌표 : (" << upLeft.GetX() << ", " << upLeft.GetY() << ")" << endl ;
    cout << "우하단의 좌표 : (" << lowRight.GetX() << ", " << lowRight.GetY() << ")" << endl ;
}

#ifdef P3
int main(){
    Point tl, br ;  //topLeft & bottomRight
    Rectangle Rect ;

    cout << "첫 번째 점의 좌표를 입력하세요(x y) : " ;
    int temp[2] ;
    for(int i = 0 ; i < 2 ; i++)
        cin >> temp[i] ;
    tl.initMembers(temp[0], temp[1]) ;

    cout << "두 번째 점의 좌표를 입력하세요(x y) : " ;
    for(int i = 0 ; i < 2 ; i++)
        cin >> temp[i] ;
    br.initMembers(temp[0], temp[1]) ;
    
    Rect.initMembers(tl, br) ;

    Rect.showRectInfo() ;

    return 0 ;
}
#endif


/*
문제 4: Rectangle 클래스 추가 함수
1. 이전 문제의 Rectangle Class 의 전용 생성자를 두가지로 overloading 가능하도록 만들어라.
1) 인자가 없는 생성자
2) 두개의 점이 인자로 주어지는 생성자

2. Rectangle 객체와 Point객체의 정보를 출력하는 연산자 <<를 정의하라 friend 함수를 이용하여 Point 멤버를 직접 접근하라.
3. Point 객체 두개를 더하는 연산함수를 friend 함수로 정의하라.

main() {
Rectangle a (Point(10,20), Point (30, 50)); 
Rectangle b ; // 모든 꼭지점이 (0,0)으로 초기화 
Point pt1(100,200), pt2 (180, 300); 
b.initMembers(pt1, pt2);
a.showRectInfo();
b.showRectInfo();
cout << a <<b;
cout << Add_point(pt1, pt2);
}
*/

ostream & operator<<(ostream &os, Point p)
{
    cout << "점의 좌표 : (" << p.GetX() << ", " << p.GetY() << ")" << "\n" << endl ;

    return os ;
}

ostream & operator<<(ostream &os, Rectangle R)
{
    os << "좌상단의 좌표 : (" << R.upLeft.GetX() << ", " << R.upLeft.GetY() << ")" << endl ;
    os << "우하단의 좌표 : (" << R.lowRight.GetX() << ", " << R.lowRight.GetY() << ")" << endl ;

    return os ;
}
/*
함수로 클래스를 접근하기 위해서는 해당 클래스에 소속되어 있어야 합니다.
하지만 friend로 선언을 하게되면 클래스의 맴버가 아니어도 접근이 가능합니다.
*/
Point Add_point(Point &ul, Point &lr)
{
    Point p ;
    p.x = ul.GetX() + lr.GetX() ;
    p.y = ul.GetY() + lr.GetY() ;
    
    return p ;
}

#ifdef P4

int main() {
    Rectangle a (Point(10,20), Point (30, 50)); 
    Rectangle b ; // 모든 꼭지점이 (0,0)으로 초기화 
    Point pt1(100,200), pt2 (180, 100);     //좌상당 우하단이 아님 

    b.initMembers(pt1, pt2);
    a.showRectInfo();
    b.showRectInfo();

    cout << "--------" << endl ; 
    cout << a << b;
    cout << Add_point(pt1, pt2) ;
}

#endif