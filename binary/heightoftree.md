<!-- 104. Maximum Depth of Binary Tree
Solved
Easy
Topics
premium lock icon
Companies
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node. -->



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void checkheight(TreeNode* root, int& max_height, int count) {
        if (root == nullptr) {
            return;
        }

        max_height = max(max_height, count);
        checkheight(root->left, max_height, count + 1);

        checkheight(root->right, max_height, count + 1);
    }
    int maxDepth(TreeNode* root) {
        int max_height = 0;
        int count = 1;
        checkheight(root, max_height, count);

        return max_height;
    }
};