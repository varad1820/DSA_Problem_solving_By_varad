class Solution {
public:
    int check(int n, vector<int>& dp, int i){
        if(i == n){
            return 1;
        }

        if(dp[i] != -1 ) return dp[i];
        
        int left = check(n,dp,i+1);
        int right{0};
        if(i+2 <= n){
            right = check(n,dp,i+2);
        }

        return dp[i] = left+right;
    }
    int climbStairs(int n) {
        vector<int> dp (n+1, -1);   
        int count = 0;
        return check(n,dp,count);
    }
};