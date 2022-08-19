/*
 * @Descroption: LeetCode 543. 二叉树的直径
 * @Author: EmoryHuang
 * @Date: 2021-07-30 15:47:36
 * @Method:
 * 深度优先搜索
 * 转换一下题目的意思也就是求二叉树左右子树的深度
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
    int ans = 1;
    int depth(TreeNode* node) {
        if (!node) return 0;
        int l = depth(node->left);
        int r = depth(node->right);
        ans = max(ans, l + r + 1);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans - 1;
    }
};