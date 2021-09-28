/*
 * @Descroption: LeetCode 437. 路径总和 III
 * @Author: EmoryHuang
 * @Date: 2021-09-28 16:43:30
 * @Method:
 * dfs
 * 建立双重递归，第一个递归遍历每个节点，将其作为起始节点
 * 第二个递归处理以每个 root 为根节点的树
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
    int ans = 0, t;
    void dfs1(TreeNode* root) {
        if (!root) return;
        dfs2(root, root->val);
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(TreeNode* root, int val) {
        if (val == t) ans++;
        if (root->left) dfs2(root->left, val + root->left->val);
        if (root->right) dfs2(root->right, val + root->right->val);
    }
    int pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        dfs1(root);
        return ans;
    }
};