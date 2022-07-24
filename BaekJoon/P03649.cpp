//P_3649

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int main(int argc, const char * argv[]) {
    // width of hole, x (1 ≤ x ≤ 20, x is Natual), cm
    short x; 
    cin >> x ;
    
    // nember of lego piece(0 ≤ n ≤ 1000000)
    int n;
    cin >> n ;
    
    // next line
    // ℓ is pasitive number, nano-meter. block size less than 10cm(100000000 nano-meter)
    vector <int> l ;
    int temp;
    for(int i = 0 ; i < n ; i++){
        cin >> temp ;
        l.push_back(temp) ;
    }

    
    sort(l.begin(), l.end()) ;


    for(int i = 0 ; i < n ; i++){
        cout << l[i] << endl;
    }

    int l1, l2;
    
    vector<int>::iterator iter = l.begin() ;
    vector<int>::iterator curr = l.end() ;

    l2 = *curr ;
    l1 = x * 10000000 - l2 ;     //x * 1cm
    if(*iter != l1){
        --curr;
        for (; iter != curr; ++iter){
            
            if(*iter< l1){
                continue ;
            }
            else if(*iter == l1)
                break;
            else{   // (*iter > l1)
                l2 = *curr ;
                l1 = x * 10000000 - l2 ;     //x * 1cm
                --curr;
            }
        }
    }

        
    if(*iter == l1)
        printf("yes %d %d\n", l1, l2);
    else
        printf("danger") ;

    return 0 ;
}