/*
 * @Descroption: LeetCode 236. 二叉树的最近公共祖先
 * @Author: EmoryHuang
 * @Date: 2021-06-04 13:31:00
 * @解题思路:
 * 遍历左分支右分支
 * 当left和right都不为空的时候说明他们分别在某一个root的左右分支中
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left == nullptr ? right : left;
    }
};