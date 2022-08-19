/*
 * @Descroption: LeetCode 236. �������������������
 * @Author: EmoryHuang
 * @Date: 2021-06-04 13:31:00
 * @����˼·:
 * �������֧�ҷ�֧
 * ��left��right����Ϊ�յ�ʱ��˵�����Ƿֱ���ĳһ��root�����ҷ�֧��
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