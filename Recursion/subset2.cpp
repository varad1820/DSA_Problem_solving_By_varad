
// leet code 99
/* Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 */
#include<vector>
#include<iostream>
#include<algorithm>

class Solution {
    void getSum(vector<int>& nums, vector<vector<int>>& ans, vector<int> sum, int id) {
        ans.push_back(sum);
        for (int i = id; i < nums.size(); i++) {
            if (i > id && nums[i] == nums[i - 1])
                continue;
            sum.push_back(nums[i]);
            getSum(nums, ans, sum, i + 1);
            sum.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> sum;
        int id = 0;
        getSum(nums, ans, sum, id);
        return ans;
    }
};