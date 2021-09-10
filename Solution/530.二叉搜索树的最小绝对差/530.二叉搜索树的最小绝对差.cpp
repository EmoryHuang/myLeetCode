/*
 * @Descroption: LeetCode 530. 二叉搜索树的最小绝对差
 * @Author: EmoryHuang
 * @Date: 2021-04-13 18:09:36
 * @解题思路: 因为是二叉搜索树，通过中序遍历，寻找最小值
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
    int ans = INT_MAX;
    TreeNode* pre = nullptr;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (pre != nullptr) ans = min(root->val - pre->val, ans);
        pre = root;
        dfs(pre->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};