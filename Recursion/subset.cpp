
// subset 1
// Given an array nums of n integers. Return array of sum of all subsets of the array nums.
// Output can be returned in any order.

#include<vector>
#include<iostream>
#include<algorithm>

class Solution {
  private:
    void getSum(vector<int>& nums, vector<int>& ans, int sum, int id) {
        if (id == nums.size()) {
            ans.push_back(sum);
            return;
        }

        // Include current element
        getSum(nums, ans, sum + nums[id], id + 1);

        // Exclude current element
        getSum(nums, ans, sum, id + 1);
    }

  public:
    vector<int> subsetSums(vector<int>& nums) {
        vector<int> ans;
        getSum(nums, ans, 0, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
