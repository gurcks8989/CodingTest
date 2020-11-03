#include <iostream>

#define range(x) (-10000 <= x && x <= 10000)

using namespace std;

void compare(int a, int b);

int main(){
    
    int a, b, c;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;

    compare(a, b) ;
        
    return 0 ;
}

void compare(int a, int b){

    int case_ = -1;
    enum{Large, Equal, Small} ;

    if(a > b)
        case_ = Large ; 
    else if(a == b)
        case_ = Equal ; 
    else//(a < b)
        case_ = Small ; 

    switch (case_)
    {
    case Large:
        cout << ">" << endl;
        break;
    case Equal:
        cout << "==" << endl;
        break;
    case Small:
        cout << "<" << endl;
        break;
    default:
        break;
    }
    
}
