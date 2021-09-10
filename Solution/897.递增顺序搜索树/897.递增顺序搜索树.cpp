/*
 * @Descroption: LeetCode 897. 递增顺序搜索树
 * @Author: EmoryHuang
 * @Date: 2021-04-25 12:59:36
 * @解题思路:
 * 中序遍历，并同时改变结点顺序
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
    TreeNode* pre;  // 前置结点
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->left);
        pre->right = root;
        root->left = nullptr;
        pre = root;
        inorder(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode* dummy = new TreeNode(0);
        pre = dummy;
        inorder(root);
        return dummy->right;
    }
};