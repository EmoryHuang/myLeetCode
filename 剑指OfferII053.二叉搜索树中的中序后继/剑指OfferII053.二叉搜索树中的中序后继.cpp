/*
 * @Descroption: ��ָ Offer II 053. �����������е�������
 * @Author: EmoryHuang
 * @Date: 2021-09-08 15:51:12
 * @Method:
 * ����һ���������
 * �����������¼�ڵ��ǰ������������ҵ�ָ���ڵ�����һ���ڵ�
 *
 * ������������������������
 * ����ǰ�ڵ��ֵС�ڵ��ڽڵ� p ��ֵ����ô�ڵ� p ����һ���ڵ�Ӧ���ڵ�ǰ�ڵ��������
 * ����ǰ�ڵ��ֵ���ڽڵ� p ��ֵ����ô��ǰ�ڵ���п����ǽڵ� p ����һ���ڵ�
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
    // ����һ���������
    // TreeNode* pre = nullptr;
    // TreeNode* ans = nullptr;
    // void inorder(TreeNode* root, TreeNode* p) {
    //     if (!root) return;
    //     inorder(root->left, p);
    //     if (pre == p) ans = root;
    //     pre = root;
    //     inorder(root->right, p);
    // }
    // TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    //     inorder(root, p);
    //     return ans;
    // }

    // ������������������������
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        while (root) {
            // ����ǰ�ڵ�ֵ���ڽڵ� p
            if (root->val > p->val) {
                ans = root;
                // ����Ѱ�Ҹ�С��Ԫ��
                root = root->left;
            } else
                // ����Ѱ�Ҹ����Ԫ��
                root = root->right;
        }
        return ans;
    }
};