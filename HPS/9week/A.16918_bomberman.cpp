// P_16918

#include <iostream>

using namespace std ;

int main(){

    // 1 <= R, C, N <= 200
    int R, C, N ;

    cin >> R >> C >> N;

    int count = 1;

    char matrix[C][R] ;

    for(int y = 0 ; y < R; y++)
        for(int x = 0; x < C; x++)
            cin >> matrix[x][y] ;

    do{

        count += 1;

        for(int y = 0 ; y < R; y++){
            for(int x = 0; x < C; x++){
                if(matrix[x][y] == 'O')
                    matrix[x][y] = 'X' ;
                else
                    matrix[x][y] = 'O' ;
            }
        }
        if(count == N)
            break ;

        count += 1;


        //bomb

        for(int y = 0 ; y < R; y++){
            for(int x = 0; x < C; x++){
                if(matrix[x][y] == 'X'){
                    if(x != 0 && matrix[x-1][y] != 'X')
                        matrix[x-1][y] = '.';
                    if(y != 0 && matrix[x][y-1] != 'X')
                        matrix[x][y-1] = '.';
                    if(x != C-1 && matrix[x+1][y] != 'X')
                        matrix[x+1][y] = '.';
                    if(y != R-1 && matrix[x][y+1] != 'X')
                        matrix[x][y+1] = '.';
                    matrix[x][y] = '.';
                }
            }
        }
    }while(count != N);
    
    for(int y = 0 ; y < R; y++){
        for(int x = 0; x < C; x++){
            if(matrix[x][y] == 'X'){
                matrix[x][y] = 'O';
            }
            cout << matrix[x][y] ;
        }
        cout << "\n" ;
    }

    return 0 ;


}

