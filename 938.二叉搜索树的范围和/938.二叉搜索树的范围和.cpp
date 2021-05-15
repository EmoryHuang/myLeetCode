/*
 * @Descroption: LeetCode 938. 二叉搜索树的范围和
 * @Author: EmoryHuang
 * @Date: 2021-04-27 10:15:36
 * @解题思路:
 * 按深度优先搜索的顺序计算范围和
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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (root == nullptr) return 0;
        if (root->val > high)
            return rangeSumBST(root->left, low, high);
        else if (root->val < low)
            return rangeSumBST(root->right, low, high);
        else
            return root->val + rangeSumBST(root->left, low, high) +
                   rangeSumBST(root->right, low, high);
    }
};