/*
 * @Descroption: LeetCode 226. ��ת������
 * @Author: EmoryHuang
 * @Date: 2021-03-23 10:42:36
 * @����˼·:
 * �õݹ��˼·�Ƚϼ򵥣��ؼ���Ҫ������ݹ����������ʲô
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
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        TreeNode *rightTree = root->right;     //�ݴ�������
        root->right = invertTree(root->left);  //����
        root->left = invertTree(rightTree);   //����
        return root;
    }
};