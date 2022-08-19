/*
 * @Descroption: LeetCode 104. 二叉树的最大深度
 * @Author: EmoryHuang
 * @Date: 2021-04-18 15:06:36
 * @解题思路: 可以用递归实现，代码也比较简洁
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
    int maxDepth(TreeNode* root) {
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};