/*
 * @Descroption: 面试题 04.06. 后继者
 * @Author: EmoryHuang
 * @Date: 2022-05-16 08:56:38
 * @Method:
 * 利用二叉搜索树的性质，判断根节点与目标节点值的大小
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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        if (root->val <= p->val) {
            return inorderSuccessor(root->right, p);
        } else {
            TreeNode* left = inorderSuccessor(root->left, p);
            return left == NULL ? root : left;
        }
    }
};