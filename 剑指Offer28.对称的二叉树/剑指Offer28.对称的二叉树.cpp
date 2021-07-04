/*
 * @Descroption: ��ָ Offer 28. �ԳƵĶ�����
 * @Author: EmoryHuang
 * @Date: 2021-07-04 13:39:33
 * @����˼·:
 * �ݹ�رȽ������ڵ��Ƿ���ͬ
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
    bool cmp(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) return true;
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false;
        return cmp(root1->left, root2->right) && cmp(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return cmp(root->left, root->right);
    }
};