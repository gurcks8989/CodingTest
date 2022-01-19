/*
258. Add Digits
문제 출처: https://leetcode.com/problems/add-digits/
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.

Example 1:
Input: num = 38
Output: 2

Explanation: The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.

Example 2:
Input: num = 0
Output: 0 

Constraints:
0 <= num <= 231 - 1
*/

/*
version 1 

class Solution {
public:
    int addDigits(int num) {
        int answer = num, sum = 0 ;
        while(10 <= answer){
            while(answer != 0){
                sum += answer%10 ;
                answer /= 10 ;
            }
            answer = sum ; 
            sum = 0 ;
        }
        return answer ;
    }
};
*/

class Solution {
public:
    int addDigits(int num) {
        if(num < 10)
            return num ;
        else
            return addDigits(sumDigits(num)) ;
    }
    
    int sumDigits(int num) {
        if(num == 0)
            return 0 ;
        else
            return num % 10 + sumDigits(num/10) ;
    }
};