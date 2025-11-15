---
51

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
---



class Solution {
public:
    bool sang_na(int row, int col, vector<string>& empty) {
        int r = row;
        int c = col;

        while (r >= 0 && c >= 0) {
            if (empty[r][c] == 'Q')
                return false;
            r--;
            c--;
        }

        r = row;
        c = col;
        while (r >= 0 && c >= 0) {
            if (empty[r][c] == 'Q')
                return false;
            c--;
        }

        r = row;
        c = col;
        while (r < empty.size() && c >= 0) {
            if (empty[r][c] == 'Q')
                return false;
            c--;
            r++;
        }

        return true;
    }
    void vishye_ka(int col, vector<vector<string>>& ans, vector<string>& empty,
                   int n) {

        if (col == n) {
            ans.push_back(empty);
            return;
        }
        for (int row = 0;  row < n; row++) {
            if (sang_na(row, col, empty)) {
                empty[row][col] = 'Q';
                vishye_ka(col + 1, ans, empty, n);
                empty[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> empty(n,string(n,'.'));
        vishye_ka(0, ans, empty, n);

        return ans;
    }
};
