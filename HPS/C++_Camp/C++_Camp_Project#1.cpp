#include <iostream>

using namespace std ;

class Real_Pair{
    private:
    public:
        double x ;  // 좌표의 x 축 값
        double y ;  // 좌표의 y 축 값
        Real_Pair(){
            x = 0 ;
            y = 0 ;
        }
        Real_Pair(double in_x, double in_y){
            x = in_x ;
            y = in_y ;
        }
};

Real_Pair operator+(const Real_Pair & r1, const Real_Pair & r2)
{  
    double x = r1.x + r2.x ;
    double y = r1.y + r2.y ;
    Real_Pair R(x, y) ;
    return R ;
}

Real_Pair operator-(const Real_Pair & r1, const Real_Pair & r2)
{  
    double x = r1.x - r2.x ;
    double y = r1.y - r2.y ;
    Real_Pair R(x, y) ;
    return R ;
}

Real_Pair operator*(const Real_Pair & r1, double d)
{  
    double x = d * r1.x ;
    double y = d * r1.y ;
    Real_Pair R(x, y) ;
    return R ;
}
Real_Pair operator*(double d, const Real_Pair & r1)
{  
    return r1 * d ;
}

Real_Pair operator/(const Real_Pair & r1, double d)
{  
    double x = r1.x / d ;
    double y = r1.y /d ;
    Real_Pair R(x, y) ;
    return R ;
}

ostream & operator<<(ostream & os, Real_Pair & R)
{
    os << "(" << R.x << ", " << R.y << ")" << endl ;
    return os ;
}

double distance(Real_Pair & r1, Real_Pair & r2)
{
    Real_Pair R = r1- r2 ;
    return sqrt(R.x * R.x + R.y * R.y) ;
}

int main(){

    Real_Pair r1, r2, r3, r4 ;
    Real_Pair r5(2.5, 3.5), r6(4, 5.0) ;

    double d = distance(r6, r5) ;
    r1 = r5 + r6 ;
    r2 = r1 * 3 ;
    r3 = 3.4 * r1 ;
    r4 = r3 / 3.4 ;
    r5 = r1 - r5 ;

    cout << r1 << r2 << r3 << r4 << r5 << endl ;
    cout << d << endl ;

    return 0 ;

}