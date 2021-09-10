/*
 * @Descroption: LeetCode 112. 路径总和
 * @Author: EmoryHuang
 * @Date: 2021-05-09 15:47:36
 * @解题思路: 深度优先，若为叶子结点，则判断 `targetSum - root->val == 0` ，否则递归的遍历左右子树。
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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (root == nullptr) return false;
        if (!root->left && !root->right) {
            return targetSum - root->val == 0;
        }
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};