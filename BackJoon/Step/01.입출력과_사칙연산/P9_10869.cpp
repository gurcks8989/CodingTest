#include <iostream>

#define range(x) (1 <= x && x <= 10000)

using namespace std;

void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void dvi(int a, int b);
void reamin(int a, int b);

int main(){
    
    int a, b ;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;
  
    add(a, b) ;
    sub(a, b) ;
    mul(a, b) ;
    dvi(a, b) ;
    reamin(a, b) ;
    
    return 0 ;
}


void add(int a, int b){

    int sum = a + b ;

    cout << sum << endl;

}

void sub(int a, int b){

    int sub = a - b ;

    cout << sub << endl;
}

void mul(int a, int b){

    int mul = a * b ;
    
    cout << mul << endl;
}

void dvi(int a, int b){
    
    int dvi = a / b ;
    
    cout << dvi << endl;

}

void reamin(int a, int b){

    int remain = a % b;

    cout << remain << endl;

}