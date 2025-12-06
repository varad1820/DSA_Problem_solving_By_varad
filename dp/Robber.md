class Solution {
public:
    int check(int n, vector<int>& nums, vector<int>& dp) {
        if (n == 0)
            return nums[n];
        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + check(n - 2, nums, dp);
        int npick = 0 + check(n - 1, nums, dp);

        return dp[n] = max(pick, npick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        // return check(n-1,nums,dp);

        // dp[0] = nums[0];
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
};
