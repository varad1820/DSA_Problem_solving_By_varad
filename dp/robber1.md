213. House Robber II
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 
class Solution {
public:
    int rob1(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        
        int pre = nums[0];
        int pre2 = 0;

        for (int i = 1; i < n; i++) {
            int take = nums[i];
            if (i > 1)
                take += pre2;

            int ntake = 0 + pre;

            int curr = max(take, ntake);
            pre2 = pre;
            pre = curr;
        }

        return pre;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> t1(n);
        vector<int> t2(n);

        for (int i = 0; i < n; i++) {
            if (i != 0)
                t1[i] = nums[i];
            if (i != n - 1)
                t2[i] = nums[i];
        }

        return max(rob1(t1), rob1(t2));
    }
};