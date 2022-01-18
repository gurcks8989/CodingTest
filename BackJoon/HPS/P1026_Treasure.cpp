#include <iostream>
#include <vector>
#include <algorithm>

using namespace std ; 

bool descending_order(int a, int b){
    return a > b ;
}

void set_input(vector<int> & v, int n){
    int temp ;
    for(int i = 0 ; i < n ; i++){
        cin >> temp ;
        v.push_back(temp) ;
    }
}

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ; cout.tie(NULL) ;

    int N, s = 0 ;
    vector<int> A, B ;
    cin >> N ;

    set_input(A, N) ;    set_input(B, N) ;

    sort(A.begin(), A.end()) ;      sort(B.begin(), B.end(), descending_order) ;

    for(int i = 0 ; i < N ; i++)
        s += A[i] * B[i] ;
    
    cout << s << endl ;
    return  0 ;
}