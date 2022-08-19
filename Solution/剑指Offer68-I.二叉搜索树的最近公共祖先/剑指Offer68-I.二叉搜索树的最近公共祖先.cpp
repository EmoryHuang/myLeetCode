/*
 * @Descroption: 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先
 * @Author: EmoryHuang
 * @Date: 2021-07-04 15:23:43
 * @解题思路:
 * 根据二叉搜索树的性质递归遍历
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
        if (root == nullptr) return nullptr;
        // p, q 都在左子树
        if (root->val > q->val && root->val > p->val) 
            return lowestCommonAncestor(root->left, p, q);
        // p, q 都在右子树
        if (root->val < q->val && root->val < p->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};