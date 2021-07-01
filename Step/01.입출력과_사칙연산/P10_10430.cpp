#include <iostream>
#include <vector>

#define range(x) (2 <= x && x <= 10000)

using namespace std;

void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void dvi(int a, int b);
void reamin(int a, int b);

int main(){
    
    int a, b, c;
    
    do{
        cin >> a;
    }while(!range(a)) ;

    do{
        cin >> b;
    }while(!range(b)) ;

    do{
        cin >> c;
    }while(!range(c)) ;
    
    vector<int> th(4);

    th[0] = (a+b)%c;
    th[1] = ((a%c) + (b%c))%c;
    th[2] = (a*b)%c;
    th[3] = ((a%c) * (b%c))%c;

    for(int i = 0 ; i < th.size(); i++)
        cout << th[i] << endl;     
    
    return 0 ;
}

//첫째 줄에 (A+B)%C, 둘째 줄에 ((A%C) + (B%C))%C, 셋째 줄에 (A×B)%C, 넷째 줄에 ((A%C) × (B%C))%C를 출력한다.