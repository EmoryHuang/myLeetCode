/*
 * @Descroption: LeetCode 783. 二叉搜索树节点最小距离
 * @Author: EmoryHuang
 * @Date: 2021-04-13 18:02:36
 * @解题思路:
 * 因为是二叉搜索树，通过中序遍历，寻找最小值
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
    int ans = INT_MAX;
    TreeNode* pre = nullptr;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (pre != nullptr) ans = min(root->val - pre->val, ans);
        pre = root;
        dfs(pre->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};