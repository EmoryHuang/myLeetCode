/*
 * @Descroption: LeetCode 1022. 从根到叶的二进制数之和
 * @Author: EmoryHuang
 * @Date: 2022-05-30 12:44:27
 * @Method:
 * dfs
 * 简单题，dfs 计算每条路径的和
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
    int dfs(TreeNode* node, int cur) {
        if (node == nullptr) return 0;
        cur = cur << 1 | node->val;
        // 如果是叶子结点，则返回路径上的值
        if (node->left == nullptr && node->right == nullptr) return cur;
        // 递归
        return dfs(node->left, cur) + dfs(node->right, cur);
    }
    int sumRootToLeaf(TreeNode* root) { return dfs(root, 0); }
};