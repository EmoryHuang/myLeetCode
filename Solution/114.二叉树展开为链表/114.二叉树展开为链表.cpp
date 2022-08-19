/*
 * @Descroption: LeetCode 114. ������չ��Ϊ����
 * @Author: EmoryHuang
 * @Date: 2021-05-14 16:44:28
 * @����˼·: ���ݶ�����չ��Ϊ������ص㣬���������������
 * ��¼ÿ�εݹ�����һ����㣬���ڵ����ָ��ָ��last���������ÿ�
 * Ȼ����� last = root
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
    TreeNode* last = nullptr;  // lastΪ���һ�����
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;  // �������ÿ�
        last = root;           // ����last
    }
};