/*
 * @Descroption: LeetCode 226. 翻转二叉树
 * @Author: EmoryHuang
 * @Date: 2021-03-23 10:42:36
 * @解题思路:
 * 用递归的思路比较简单，关键是要搞清楚递归它具体干了什么
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *rightTree = root->right;     //暂存右子树
        root->right = invertTree(root->left);  //交换
        root->left = invertTree(rightTree);   //交换
        return root;
    }
};