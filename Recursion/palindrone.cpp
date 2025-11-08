// 131. Palindrome Partitioning
// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

 

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]


#include<vector>
#include<iostream>
#include<algorithm>

class Solution {
    bool isPal(const string &s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }
      void dfs(const string &s, int start,
             vector<string> &curr,
             vector<vector<string>> &ans) {
        int n = s.size();
        if (start == n) {
            ans.push_back(curr);
            return;
        }

        // try every end index for substring starting at 'start'
        for (int end = start; end < n; ++end) {
            if (isPal(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, curr, ans);
                curr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        dfs(s, 0, curr, ans);
        return ans;

    }
};