#include <iostream>
#include <vector>

#define range(x) (1 <= x && x < 1000)

using namespace std;

void mul(int a, int b);

int main(){
    
    int a, b, c;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;

    vector<int> slide(3) ;

    slide[0] = b / 100 ;        //hundred
    slide[1] = (b % 100) / 10 ; //ten
    slide[2] = b % 10 ;         //one
    
    for(int i = 2 ; i >= 0; i--)
        mul(a, slide[i]) ;
    mul(a, b) ;
    
    return 0 ;
}



void mul(int a, int b){

    int mul = a * b ;
    
    cout << mul << endl;
}
