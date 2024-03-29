/*
Leetcode problem link:
https://leetcode.com/problems/two-city-scheduling/

1029. Two City Scheduling

A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], 
the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.
Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

Example 1:

Input: costs = [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation: 
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
Example 2:

Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
Output: 1859
Example 3:

Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
Output: 3086
 
Constraints:
2 * n == costs.length
2 <= costs.length <= 100
costs.length is even.
1 <= aCosti, bCosti <= 1000
*/


bool compare(vector<int>& a, vector<int>& b){
    return abs(a[0] - a[1]) > abs(b[0] - b[1]) ;
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int sum = 0, a_n = costs.size()/2, b_n = costs.size()/2 ;
        sort(costs.begin(), costs.end(), compare) ;
        for(vector<vector<int>>::iterator iter = costs.begin() ; iter != costs.end() ; iter++){
            if(b_n < 1 || (0 < a_n && (*iter)[0] < (*iter)[1]) || ((*iter)[0] == (*iter)[1] && b_n <= a_n)){
                // visite a
                a_n -= 1 ;
                sum += (*iter)[0] ;
            }
            else if(a_n < 1 || (0 < b_n && (*iter)[0] > (*iter)[1]) || ((*iter)[0] == (*iter)[1] && a_n <= b_n)){
                // visite b
                b_n -= 1 ;
                sum += (*iter)[1] ;
            }
        }
        return sum ;
    }
};