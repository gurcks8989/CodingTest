/*
14. Longest Common Prefix
문제 출처:https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Constraints:
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string answer = "" ;
        bool is_common = true ;
        int minimum = 200 ;
        
        for(string str : strs)
            if(str.length() < minimum)
                minimum = str.length() ;
        
        for(int i = 0 ; i < minimum ; i++){
            char c = strs[0][i] ; 
            for(int j = 1 ; j < strs.size() ; j++){
                if(c != strs[j][i]){
                    is_common = false ;
                    break ;
                }
            }
            if(is_common)
                answer.push_back(c) ;
            else
                break ;
        }
        return answer ;
    }
};