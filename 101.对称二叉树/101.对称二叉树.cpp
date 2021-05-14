/*
 * @Descroption: LeetCode 101. �Գƶ�����
 * @Author: EmoryHuang
 * @Date: 2021-04-18 14:36:36
 * @����˼·: ����һ�� [100. ��ͬ����]��ͬ�������޸ļ���
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
    bool cmp(TreeNode* a, TreeNode* b) {
        if (a == nullptr && b == nullptr) return true;
        if (a == nullptr || b == nullptr) return false;
        if (a->val != b->val) return false;
        return cmp(a->left, b->right) && cmp(a->right, b->left);
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return cmp(root->left, root->right);
    }
};