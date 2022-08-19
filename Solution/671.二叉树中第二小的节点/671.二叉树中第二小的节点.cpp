/*
 * @Descroption: LeetCode 671. 二叉树中第二小的节点
 * @Author: EmoryHuang
 * @Date: 2021-07-27 13:51:29
 * @Method:
 * 根节点一定小于等于左右子节点，二叉树的根节点为最小的节点
 * 那么题目就变成了求左右子树中最小的节点
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
    int dfs(TreeNode* node, int val) {
        if (node == nullptr) return -1;
        if (node->val > val) return node->val;
        int l = dfs(node->left, val);
        int r = dfs(node->right, val);
        if (l > val && r > val) return min(l, r);
        return max(l, r);
    }
    int findSecondMinimumValue(TreeNode* root) { return dfs(root, root->val); }
};