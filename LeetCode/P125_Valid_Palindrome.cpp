/*
125. Valid Palindrome
문제 출처:https://leetcode.com/problems/valid-palindrome/

A phrase is a palindrome if, after converting all uppercase letters
into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.


Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.

Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        bool answer = true ;
        int left = 0, right = s.length()-1 ; 
        while(left < right){
            if(!isalpha(s[left]) && !isdigit(s[left])){
                left ++ ;
                continue ;
            }
            if(!isalpha(s[right]) && !isdigit(s[right])){
                right -- ;
                continue ;
            }
            if(tolower(s[left++]) != tolower(s[right--])){
                answer = false ;
                break ;
            }
        }
        return answer ;
    }
};