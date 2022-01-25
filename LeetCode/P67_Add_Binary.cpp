/*67. Add Binary
문제 출처:https://leetcode.com/problems/add-binary/

Given two binary strings a and b, return their sum as a binary string.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:
1 <= a.length, b.length <= 104
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/

class Solution {
public:
    string addBinary(string a, string b) {
        short a_idx = a.length(), b_idx = b.length();
        string answer = "" ;
        short remain =  0; 
        int num ;
        while(0 < a_idx || 0 < b_idx){
            num = remain ;
            if(0 < a_idx)
                num += a[--a_idx] - '0' ;
            if(0 < b_idx)
                num += b[--b_idx] - '0' ;
            remain = num / 2 ;
            num %= 2 ;
            answer.push_back(num + '0') ;
        }
        if(0 < remain)
            answer.push_back(remain + '0') ;
        reverse(answer.begin(), answer.end()) ;
        return answer ;
    }
};