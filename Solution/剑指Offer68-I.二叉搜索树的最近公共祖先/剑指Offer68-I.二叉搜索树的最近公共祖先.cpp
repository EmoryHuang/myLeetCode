/*
 * @Descroption: ��ָ Offer 68 - I. �����������������������
 * @Author: EmoryHuang
 * @Date: 2021-07-04 15:23:43
 * @����˼·:
 * ���ݶ��������������ʵݹ����
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
        // p, q ����������
        if (root->val > q->val && root->val > p->val) 
            return lowestCommonAncestor(root->left, p, q);
        // p, q ����������
        if (root->val < q->val && root->val < p->val)
            return lowestCommonAncestor(root->right, p, q);
        return root;
    }
};