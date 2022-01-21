#include <iostream>

using namespace std ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;     cout.tie(NULL) ;
    int T ;
    double num ; 
    cin >> T ;  

    cout << fixed;
    cout.precision(2);

    for(int i = 0 ; i < T ; i++){
        cin >> num ;
        string line ;
        getline(cin, line) ; 
        for(auto c : line)
            switch (c){
                case '@' :  num *= 3 ;  break ;
                case '%' :  num += 5 ;  break ;
                case '#' :  num -= 7 ;  break ;
            }
        cout << num << endl ;
    }
    return 0 ;
}