/*
 * @Descroption: LeetCode 404. 左叶子之和
 * @Author: EmoryHuang
 * @Date: 2021-03-26 15:46:36
 * @解题思路: 简单递归
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        int ans = 0;
        if (root->left && root->left->left == NULL && root->left->right == NULL)
            ans += root->left->val;
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right) + ans;
    }
};