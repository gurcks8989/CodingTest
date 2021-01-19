

#define P1 
//#define P2

#include <iostream>

using namespace std ;

int gid(0) ;

/*
문제 1: 복사 생성자 만들기
1. 3장의 Rectangle 클래스와 Point 클래스의 복사 생성자를 만들어라
main() {
Point pt1(10,20);
Rectangle a (pt1, Point (30,40); Rectangle b (a);
cout << a;
cout << b;
}
출력:
Constructor called with (10,20) (ID=1)
Constructor called with (30,40) (ID=2)
Constructor called with (10,20) , (30,40) (ID=3) 
Copy Constructor called with (10,20), (30,40) (ID=4) 
Rectangle (10,20), (30,40) (ID=3)
Rectangle (10,20), (30,40) (ID=4)
Destructor called (ID=4)
Destructor called (ID=3)
Destructor called (ID=2)
Destructor called (ID=1)

*/

#ifdef P1

class Point{ 
    private:
        int x; //x좌표
        int y; //y좌표 
        int id ;
    public:
        Point(){
            x = 0 ;
            y = 0 ;
        }
        Point(int xpos, int ypos){
            x = xpos ;
            y = ypos ;
            id ++ ;
            gid++ ;
            cout << "Constructor called with (" << x << "," << y << ") (ID=" << gid << ")" << endl ;
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

class Rectangle{ 
    private:
        Point upLeft;
        Point lowRight; 
        int id ;
    public:
        Rectangle(){
            upLeft.initMembers(0, 0) ;
            lowRight.initMembers(0, 0) ;
            id = 1 ;
            gid++; 
            cout << "Constructor called with (" << upLeft.GetX() << "," << upLeft.GetY() << "), (" 
            << lowRight.GetX() << "," << lowRight.GetY() << ") (ID=" << gid << ")" << endl ;
        }
        Rectangle(Point ul, Point lr){
            upLeft = ul ;
            lowRight = lr ;
            id++ ;
            gid++ ;
            cout << "Constructor called with (" << upLeft.GetX() << "," << upLeft.GetY() << "), (" 
            << lowRight.GetX() << "," << lowRight.GetY() << ") (ID=" << gid << ")" << endl ;
        }
        ~Rectangle(){
            id-- ;
            gid --; 
            cout << "Destructor called (ID=" << gid << ")" << endl ;
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

ostream & operator<<(ostream &os, Point p)
{
    cout << "점의 좌표 : (" << p.GetX() << ", " << p.GetY() << ")" << "\n" << endl ;

    return os ;
}

ostream & operator<<(ostream &os, Rectangle R)
{
    gid++ ;
    os << "Rectangle (" << R.upLeft.GetX() << "," << R.upLeft.GetY() << "), (" 
    << R.lowRight.GetX() << "," << R.lowRight.GetY() << ") (ID=" << gid << ")" << endl ;

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

int main() {
    Point pt1(10,20);
    Rectangle a (pt1, Point (30,40)) ; 
    Rectangle b (a);
    cout << a;
    cout << b;
}


#endif


/*
문제 2:
다음과 같은 멤버 변수를 가지는 Person 클래스를 정의하고 멤버 함수들을 만들어라.
(인자가 name만 있는 것과 전부 있는 두종류의 생성자, 복사 생성자, 소멸자 포함해서) char * name;
int height;
int weight ;
2. Assignment operator overloading도 정의하라.
main() {
Person p1 (“James”, 150, 50); Person p2 (“Trump”);
Person p3 = p1;
p3 = p2;
cout << p1 << p2 << p3
}
*/



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