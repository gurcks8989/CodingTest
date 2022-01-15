/*
136. Single Number
문제 출처: https://leetcode.com/problems/single-number/

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
 
Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1
 

Constraints:
1 <= nums.length <= 3 * 104
-3 * 104 <= nums[i] <= 3 * 104
Each element in the array appears twice except for one element which appears only once.
*/
#define MAXSIZE 30000

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int positive[MAXSIZE] = {0, }, negative[MAXSIZE]={0, } ;
        for(vector<int>::iterator iter = nums.begin() ; iter != nums.end() ; iter++){
            if(0 <= *iter)
                positive[*iter] += 1 ;
            else
                negative[-(*iter)] += 1;
        }
        
        int answer = MAXSIZE ;
        for(int i = 0 ; i < MAXSIZE && answer == MAXSIZE ; i++){
            if(positive[i] == 1)
                answer = i ;
            else if(negative[i] == 1)
                answer = -i ;
        }
        return answer ;
    }
};