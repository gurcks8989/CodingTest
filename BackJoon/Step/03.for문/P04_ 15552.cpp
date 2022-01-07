/*

*/

#include <iostream>
#include <vector>

                    //  1000 * -1000            1000 * 1000
#define range(x) (x != 0 && -1000000 <= x && x <= 1000000)

using namespace std;

int main(){
    
    /*
    정수 x (−1000 ≤ x ≤ 1000; x ≠ 0) 
    정수 y (−1000 ≤ y ≤ 1000; y ≠ 0)
    */
    int x, y;
    
    cin >> x;
    cin >> y;
    
    if(!range(x*y))
        return -1 ;

    //Quadrant n
    int n = 0 ;

    // 1 or 4
    if(x > 0){
        // 1
        if(y > 0)
            n = 1 ;
        // 4
        else
            n = 4 ;
    }
    // 2 or 3
    else{
        // 2
        if(y > 0)
            n = 2 ;
        // 3
        else
            n = 3; 
    }

    cout << n << endl ; 

    return 0 ;
}