/*
 * @Descroption: LeetCode 814. 二叉树剪枝
 * @Author: EmoryHuang
 * @Date: 2021-05-22 14:20:00
 * @解题思路:
 * 递归
 * 如果 root 的左右孩子为根的子树不包含 1，那就把对应的指针置为空
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
    TreeNode *pruneTree(TreeNode *root) {
        if (root == nullptr) return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0) return nullptr;
        return root;
    }
};