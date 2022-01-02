// P_16918

#include <iostream>

using namespace std ;

int main(){

    /*
    2 ≤ H, W ≤ 300
    1 ≤ X < H
    1 ≤ Y < W
    0 ≤ Bi,j ≤ 1,000
    */

    int H, W, X, Y ;

    cin >> H >> W >> X >> Y;


    int A[H][W], B[H+X][W+Y] ;
    
    for(int x = 0 ; x < H+X; x++)
        for(int y = 0; y < W+Y; y++)
            cin >> B[x][y] ;

    for(int x = 0 ; x < H+X; x++)
        for(int y = 0; y < W+Y; y++){
            if(x < Y)
                A[x][y] = B[x][y] ;
            if(y < X)
                A[x][y] = B[x][y] ;
            
            if(x >= Y && y >= X){
                A[x][y] = B[x+Y][y+X] ;
            }
        }
    
    for(int x = 0 ; x < H; x++){
        for(int y = 0; y < W; y++)
            cout << A[x][y] << " " ;
        cout << "\n";
    }
    

    return 0 ;


}

