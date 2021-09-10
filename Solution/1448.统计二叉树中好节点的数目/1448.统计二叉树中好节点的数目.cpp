/*
 * @Descroption: LeetCode 1448. 统计二叉树中好节点的数目
 * @Author: EmoryHuang
 * @Date: 2021-08-23 17:15:22
 * @Method:
 * dfs
 * 二叉树前序遍历，同时维护当前路径上的最大值
 * 若当前节点值大于等于路径上的节点值，那么ans + 1
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
    void dfs(TreeNode* root, int n) {
        if (root->val >= n) {
            ans++;
            n = root->val;
        }
        if (root->left) dfs(root->left, n);
        if (root->right) dfs(root->right, n);
    }
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
};