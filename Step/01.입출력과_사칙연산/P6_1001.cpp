#include <iostream>

using namespace std;

int main(){
    
    int a, b ;
    
    do{
        cin >> a;
    }while(a <= 0) ;

    do{
        cin >> b;
    }while(10 <= b) ;
  
    int sub = a - b ;
    
    cout << sub << endl;
    
    return 0 ;
}