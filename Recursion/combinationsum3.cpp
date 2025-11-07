/*  216. Combination Sum III
Solved
Medium

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:

Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

*/

#include<vector>
#include<iostream>
#include<algorithm>

class Solution {
    void getsubset(vector<vector<int>>& ans, vector<int>& temp, int sum, int id,
                   int ni, int size, int final) {
   

        // base: picked required count
        if (id == size) {
            if (sum == final) {
                ans.push_back(temp);
            }
            return;
        }

        if (ni > 9)
            return;

        // PICK branch: only if picking doesn't exceed final
        if (sum + ni <= final) {
            sum += ni;
            temp.push_back(ni);
            getsubset(ans, temp, sum, id + 1, ni + 1, size,
                      final); // id increments only when picked
            temp.pop_back();
            sum -= ni;
        }

        // EXCLUDE branch: try next number without incrementing id
        getsubset(ans, temp, sum, id, ni + 1, size, final);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        int id = 0; // how many picked so far
        int ni = 1; // current candidate number (1..9)
        int sum = 0;
        getsubset(ans, temp, sum, id, ni, k, n);
        return ans;
    }
};
