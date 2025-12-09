#include <bits/stdc++.h>
using namespace std;

int check(int n, int last, vector<vector<int>>& dp, vector<vector<int>>& points) {
    if (n == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; ++i) {
            if (i != last)            // respect the last activity constraint
                {maxi = max(maxi, points[0][i]);}
        }
        return maxi;
    }

    if (dp[n][last] != -1) return dp[n][last];

    int maxi = 0;
    for (int i = 0; i < 3; ++i) {
        if (i != last) 
        {
            int point = points[n][i] + check(n - 1, i, dp, points);
            maxi = max(maxi, point);
        }
    }

    return dp[n][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>>& points) {
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return check(n - 1, 3, dp, points);
}
