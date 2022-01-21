/*
초등학교교 학생인 정우와 석환이는 최근 학교에서 두 이진수의 XOR 연산에 대해 배웠다.
 둘은 매우 영특한 학생이라 새로 배운 연산을 갖고 이리저리 장난치기 시작했다.
 다만 석환이는 정우에게 일을 시키는 것을 좋아하는지라 다음과 같은 제안을 했다.

“내가 N개의 10진수를 주면, 등장하는 숫자들 중 홀수번만 나타나는 숫자들을 모두 XOR한 결과를 구해줘.”

예를 들어 '2, 5, 3, 3' 이 주어질 경우, '2'와'5'는 1번(홀수 번) 나타나고 '3' 은 2번 (짝수 번) 나타나므로
홀수 번 나타난 '2' 와 '5'를 XOR 한 결과를 구해야 하고,
'2, 5, 3, 3, 2, 4, 5, 3' 이 주어질 경우 '2' 와 '5' 는 2번 나타나고, '3' 은 3번, '4' 는 1번 나타나므로
홀수 번 나타난 '3' 과 '4'를 XOR 한 결과를 구해야 한다.

정우는 제안을 수락했지만, 가면 갈수록 매번 XOR 연산을 수행하는 일에 지치고 있다.
정우를 도와서 주어 진 문제를 해결하는 프로그램을 작성하라.

- 제한시간: 전체 테스트 케이스는 20개 이하이며, 전체 수행 시간은 1초 이내. (Java 2초 이내) 
    제한 시간을 초과하면 제출한 소스코드의 프로그램이 즉시 종료되며,
    그때까지 수행한 결과에서 테스트 케이스를 1개 그룹 이상 통과하였더라도 점수는 0점이 됩니다.
    그러나, 제한 시간을 초과하더라도 테스트 케이스를 1개 그룹 이상 통과하였다면 '부분 점수(0< 점수< 만점)'를 받을 수 있으며,
    이를 위해서는, C / C++ 에서 "printf 함수" 사용할 경우, 프로그램 시작부분에서 "setbuf(stdout, NULL);"를 한번만 사용하십시오.
    C++에서는 "setbuf(stdout, NULL);"와 "printf 함수" 대신 "cout"를 사용하고, Java에서는 "System.out.printIn"을 사용하시면,
    제한 시간을 초과하더라도 '부분 점수'를 받을 수 있습니다.                                     
    ※ 언어별 기본 제공 소스코드 내용 참고
    만약, 제한 시간을 초과하지 않았는데도 '부분 점수'를 받았다면, 일부 테스트 케이스를 통과하지 못한 경우 입니다.

- 메모리 사용 제한 : heap, global, static 총계 256MB, stack 1MB

메모리 사용 제한
heap, global, static (총계) : 256MB
stack : 1MB
입력
입력 파일에는 여러 테스트 케이스가 포함될 수 있다.
파일의 첫째 줄에 케이스의 개수를 나타내는 자연수 T 가 주어지고,
이후 차례로 T 개의 테스트 케이스가 주어진다. ( 1≤T≤20 )
각각의 테스트 케이스 첫 번째 줄에는 석환이가 말한 숫자 N ( N  은 3,000,000 이하의 자연수)이 주어진다.
테스트 케이스의 둘째 줄에는 N개의 숫자들이 공백(빈칸)을 사이에 두고 주어진다.
각 숫자는 32bit 정수형 변수에 담을 수 있는 음이 아닌 정수이다.

출력
각 테스트 케이스의 답을 순서대로 표준출력으로 출력하여야 하며,
각 테스트 케이스마다 첫 줄에는  “Case #T”를 출력하여야 한다. 이때 T는 케이스의 번호이다.
그 다음 줄에는 주어진 숫자들 중에서 '홀수' 번만 나타나는 숫자들을 모두 XOR 한 결과를 출력한다.

입출력예
입력
1
4
2 5 3 3
출력
Case #1
7
*/

/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>

using namespace std;

int Answer;

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int N, temp ;
		cin >> N ;
		for(int i = 0 ; i < N ; i++){
		    cin >> temp ;
		    Answer ^= temp ;
		}
		
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}