/*
367. Valid Perfect Square
문제 출처:https://leetcode.com/problems/valid-perfect-square/

Given a positive integer num, write a function which returns True if num is a perfect square else False.
Follow up: Do not use any built-in library function such as sqrt.

Example 1:
Input: num = 16
Output: true

Example 2:
Input: num = 14
Output: false

Constraints:
1 <= num <= 2^31 - 1
*/
class Solution {
public:
    bool isPerfectSquare(int num) {
        int a = sqrt(num) ;
        return (a*a == num) ? true : false ;
    }
    
    int sqrt(int x) {
        //Babylonian method
        double n = 10.0;
        for(int i = 0; i < 100; i++)
            n = (n + (x / n)) / 2;
        return n;    
    }
};