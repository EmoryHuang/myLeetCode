/*
 * @Descroption: LeetCode 563. 二叉树的坡度
 * @Author: EmoryHuang
 * @Date: 2021-05-29 14:39:00
 * @解题思路:
 * 每个节点往上返回所有子节点（左+右）和自身值的和
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
   public:
    int ans = 0;
    int dfs(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans += abs(left - right);
        return left + right + root->val;
    }
    int findTilt(TreeNode *root) {
        if (root == nullptr) return 0;
        dfs(root);
        return ans;
    }
};