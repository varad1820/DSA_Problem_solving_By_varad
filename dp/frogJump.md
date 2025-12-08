#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    // Base case: frog is already at stone 0
    int prev = 0;   // dp[i-1]
    int prev2 = 0;  // dp[i-2]

    for (int i = 1; i < n; i++) {
        int oneStep = prev + abs(heights[i] - heights[i - 1]);

        int twoStep = INT_MAX;
        if (i > 1) {
            twoStep = prev2 + abs(heights[i] - heights[i - 2]);
        }

        int curr = min(oneStep, twoStep);

        // shift window for next iteration
        prev2 = prev;
        prev = curr;
    }

    return prev; // this is dp[n-1]
}
