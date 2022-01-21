/*
844. Backspace String Compare
문제 출처: https://leetcode.com/problems/backspace-string-compare/

Given two strings s and t, return true if they are equal when both are typed into empty text editors. 
'#' means a backspace character.
Note that after backspacing an empty text, the text will continue empty.

Example 1:
Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:
Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:
Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
 

Constraints:
1 <= s.length, t.length <= 200
s and t only contain lowercase letters and '#' characters.
*/

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        remove_string(s) ;  remove_string(t) ;
        return (s.compare(t) == 0) ? true : false ;
    }
    
    void remove_string(string & s){
        for(int i = 0 ; i < s.length() ; ){
            if(s[0] == '#'){
                s.erase(0, 1) ;
            }
            else if(s[i] == '#'){
                s.erase(i-1, 2) ;
                i -= 1 ; 
            }
            else
                i += 1 ;
        }
    }
};