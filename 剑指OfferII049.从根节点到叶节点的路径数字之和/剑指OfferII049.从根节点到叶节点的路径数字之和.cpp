/*
 * @Descroption: 剑指 Offer II 049. 从根节点到叶节点的路径数字之和
 * @Author: EmoryHuang
 * @Date: 2021-08-06 19:08:05
 * @Method:
 * 回溯法
 * 枚举每一条从根节点到叶子节点的路径
 * 若遍历到叶子节点，则将这条路径的和加入 ans
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
    void dfs(TreeNode* node, int cur) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) ans += cur * 10 + node->val;
        dfs(node->left, cur * 10 + node->val);
        dfs(node->right, cur * 10 + node->val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};