/*
Programmers 문제
Problem Link : https://programmers.co.kr/learn/courses/30/lessons/12977

소수 만들기
문제 설명
주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다. 숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른 3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항
nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.
입출력 예
nums	result
[1,2,3,4]	1
[1,2,7,6,4]	4
입출력 예 설명
입출력 예 #1
[1,2,4]를 이용해서 7을 만들 수 있습니다.

입출력 예 #2
[1,2,4]를 이용해서 7을 만들 수 있습니다.
[1,4,6]을 이용해서 11을 만들 수 있습니다.
[2,4,7]을 이용해서 13을 만들 수 있습니다.
[4,6,7]을 이용해서 17을 만들 수 있습니다.
*/ 

#include <vector>
#include <iostream>
#include <cmath>

#define MAXNUM 2997

using namespace std;

// 최대 합은 998 + 999 + 1000 = 2997
bool prime_numbers[MAXNUM+1] = {false, } ;

bool calculate_a_prime_number(int num){
    for(int i = 2 ;i <= int(sqrt(num)) ; i++)
        if(num % i == 0)
            return false ;
    return true ;
}

void make_an_prime_numbers(){
    for(int num = 2 ; num <= MAXNUM ; num++)
        prime_numbers[num] = calculate_a_prime_number(num) ;
}


int solution(vector<int> nums) {
    int answer = 0 ;
    
    make_an_prime_numbers() ;
    
    for(vector<int>::iterator n1 = nums.begin() ; n1 != nums.end() ; n1++)
        for(vector<int>::iterator n2 = n1+1 ; n2 != nums.end() ; n2++)
            for(vector<int>::iterator n3 = n2+1 ; n3 != nums.end() ; n3++)
                if(prime_numbers[*n1 + *n2 + *n3])
                    answer += 1 ;
    
    return answer;
}