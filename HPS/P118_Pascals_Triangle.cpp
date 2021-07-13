/*
Leetcode problem link:
https://leetcode.com/problems/pascals-triangle/

118. Pascal's Triangle
Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
*/

class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector <vector<int>> answer ;
            for(int i = 0 ; i < numRows ; i++){
                vector <int> temp ;
                if(i > 0)
                    temp.push_back(1) ;
                if(i > 1)
                    for(int j = 1 ; j < i ; j++){
                        temp.push_back(answer[i-1][j-1] + answer[i-1][j]) ;  
                    } 
                temp.push_back(1) ;
                answer.push_back(temp) ;
            }
            return answer ;
        }
};