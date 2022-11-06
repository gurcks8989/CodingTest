/*
덱
문제 출처: https://www.acmicpc.net/problem/10866

정수를 저장하는 덱(Deque)를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

명령은 총 여덟 가지이다.

push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
입력
첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 
둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 
문제에 나와있지 않은 명령이 주어지는 경우는 없다.

출력
출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.

예제 입력 1 
15
push_back 1
push_front 2
front
back
size
empty
pop_front
pop_back
pop_front
size
empty
pop_back
push_front 3
empty
front
예제 출력 1 
2
1
2
0
2
1
-1
0
1
-1
0
3
예제 입력 2 
22
front
back
pop_front
pop_back
push_front 1
front
pop_back
push_back 2
back
pop_front
push_front 10
push_front 333
front
back
pop_back
pop_back
push_back 20
push_back 1234
front
back
pop_back
pop_back
예제 출력 2 
-1
-1
-1
-1
1
1
2
2
333
10
10
333
20
1234
1234
20
*/

#include <iostream>
#include <deque>
#include <map>
 
using namespace std ;

enum commands{PUSH_FRONT, PUSH_BACK, POP_FRONT, POP_BACK, SIZE, EMPTY, FRONT, BACK} ;
map<string, commands> commandsMap = {
    {"push_front", PUSH_FRONT},
    {"push_back", PUSH_BACK},
    {"pop_front", POP_FRONT},
    {"pop_back", POP_BACK},
    {"size", SIZE},
    {"empty", EMPTY},
    {"front", FRONT},
    {"back", BACK}} ;

int main(){
    ios::sync_with_stdio(false) ;
    cin.tie(NULL) ;
    cout.tie(NULL) ;
    deque<int> store ;
    int N ;
    cin >> N ;
    for(int i = 0 ; i < N ; i++){
        string command;
        int X ; 
        cin >> command ;
        switch (commandsMap[command]){
            case PUSH_FRONT :   cin >> X ;  store.push_front(X) ;   break;
            case PUSH_BACK :    cin >> X ;  store.push_back(X) ;    break;
            case POP_FRONT :
                if(store.empty())
                    cout << -1 << "\n" ;
                else{
                    cout << store.front() << "\n" ;
                    store.pop_front() ;
                }
                break;
            case POP_BACK :
                if(store.empty())
                    cout << -1 << "\n" ;
                else{
                    cout << store.back() << "\n" ;
                    store.pop_back() ;
                }
                break;
            case SIZE:  cout << store.size() << "\n" ;  break;
            case EMPTY: cout << store.empty() << "\n" ; break;
            case FRONT: cout << (store.empty() ? -1 : store.front()) << "\n" ; break;
            case BACK:  cout << (store.empty() ? -1 : store.back()) << "\n" ;  break;
            default:    break;
        }
    }
    return 0 ;
}