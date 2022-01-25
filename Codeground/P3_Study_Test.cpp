/*
초등학생인 정우는 시험 기간을 맞아 공부를 시작해야 한다.

정우가 다니는 학교에선 총 N 개의 과목에 대해 시험을 보는데, 시간이 부족한 정우는 그 중 K 개의 과목만을 골라서 공부할 수 있다.
정우는 매우 특이한 학생이라서 어떤 과목을 공부한다면 그 과목에 대해선 무조건 같은 점수를 받게 된다고 한다.

정우는 시험 점수 총합을 최대화하기 위해 K 개의 과목을 골라야 한다.
하지만, 모든 과목을 공부할 시간이 없는 정우는, 당신에게 "최대 합계 점수"를 받을 수 있는 K개의 과목을 골라달라고 한다.
K개 과목을 골랐을 때 정우가 받을 수 있는 "최대 합계 점수"를 구하는 프로그램을 작성하라.


- 제한시간: 전체 테스트 케이스는 20개 이하이며, 전체 수행 시간은 1초 이내. (Java 2초 이내) 
    제한 시간을 초과하면 제출한 소스코드의 프로그램이 즉시 종료되며,
    그때까지 수행한 결과에서 테스트 케이스를 1개 그룹 이상 통과하였더라도 점수는 0점이 됩니다.
    그러나, 제한 시간을 초과하더라도 테스트 케이스를 1개 그룹 이상 통과하였다면 '부분 점수(0< 점수< 만점)'를 받을 수 있으며,
    이를 위해서는, C / C++ 에서 "printf 함수" 사용할 경우, 프로그램 시작부분에서 "setbuf(stdout, NULL);"를 한번만 사용하십시오.
    C++에서는 "setbuf(stdout, NULL);"와 "printf 함수" 대신 "cout"를 사용하고, Java에서는 "System.out.printIn"을 사용하시면,
    제한 시간을 초과하더라도 '부분 점수'를 받을 수 있습니다.                                     ※ 언어별 기본 제공 소스코드 내용 참고
    만약, 제한 시간을 초과하지 않았는데도 '부분 점수'를 받았다면, 일부 테스트 케이스를 통과하지 못한 경우 입니다.

- 메모리 사용 제한 : heap, global, static 총계 256MB, stack 1MB

메모리 사용 제한
heap, global, static (총계) : 256MB
stack : 1MB
입력
입력 파일에는 여러 테스트 케이스가 포함될 수 있다.
파일의 첫째 줄에 케이스의 개수를 나타내는 자연수 T 가 주어지고, 이후 차례로 T 개 테스트 케이스가 주어진다 (1≤T≤20)
입력의 첫 줄에는 테스트 케이스의 숫자가 주어진다.
각각의 테스트 케이스의 첫째 줄에는 과목의 수 N ( N 은 20만 이하의 자연수 )과 정우가 공부할 수 있는 과목의 수 K가 주어진다.
테스트 케이스의 둘째 줄에는 N 개의 숫자들이 주어진다.
각 숫자는 100이하의 음이 아닌 정수이다.고, 각 숫자는 차례대로 어떤해당하는 과목을 공부했을 때 정우가 받을 수 있는 점수를 의미한다.

출력
각 테스트 케이스의 답을 순서대로 표준출력으로 출력하여야 하며,
각 테스트 케이스마다 첫 줄에 “Case #T”를 출력하여야 한다. 이때 T는 케이스의 번호이다.
각 테스트케이스 마다 정우가 원하는 결과(K개 과목 총점의 최대값)를 출력한다.

입출력예

입력
1
4 2
20 50 30 30

출력
Case #1
80
*/
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

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
        int n, k, temp ;
        vector<int> grade ;
	    cin >> n >> k ;
	    for(int i = 0 ; i < n ; i++){
	        cin >> temp ;
	        grade.push_back(temp) ;
	    }
	    sort(grade.rbegin(), grade.rend()) ;
	    
	    for(int i = 0 ; i < k ; i++)
	        Answer += grade[i] ;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////
		
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}