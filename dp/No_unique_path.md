62. Unique Paths

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.


class Solution {
public:
    int travel(int& m, int& n, int i, int j, vector<vector<int>>& dp){
        if( dp[i][j] != -1 ) return dp[i][j];

        if(i == m-1 && j == n-1)
        {
            return 1;
        }

        int left = 0;
        int right = 0;

        if( j+1 < n ){
            left = travel(m,n,i,j+1,dp);
        }

        if( i+1 < m ){
            right = travel(m,n,i+1,j,dp);
        }

        return dp[i][j] = left+right;
    }

    int uniquePaths(int m, int n) {

        vector<vector<int>> dp (m,vector<int>(n,0));

        // for(int  j = 0; j < n; j++){
        //     dp[0][j] = 1;
        // }
        // for(int  i = 0; i < m; i++){
        //     dp[i][0] = 1;
        // }
        
        int p1 = 1;
        int p2 = 2;

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                int = dp[i-1][j] + dp[i][j-1];
                
            }
            p1  = dp[i][1];
            p2 = 1;
        }

        return dp[m-1][n-1];
    }
};