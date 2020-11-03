#include <iostream>

using namespace std;

int main(){
    
    int a, b ;

    cout.precision(10) ;
    
    do{
        cin >> a;
    }while(a <= 0) ;

    do{
        cin >> b;
    }while(10 <= b) ;
  
    double dvi = double(a) / double(b) ;

    cout << dvi << endl;
    
    return 0 ;
}