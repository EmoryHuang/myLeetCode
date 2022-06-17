/*
 * @Descroption: LeetCode 450. ɾ�������������еĽڵ�
 * @Author: EmoryHuang
 * @Date: 2022-06-02 09:10:54
 * @Method:
 * �ݹ�
 * ���Ŀ��ڵ���ڵ�ǰ�ڵ�ֵ����ȥ��������ɾ��������ȥ��������ɾ��
 * ���Ŀ��ڵ���ǵ�ǰ�ڵ㣺
 * 1. �������ӣ������Ӷ�����λ�ã�ɾ���˸ýڵ�
 * 2. �������ӣ������Ӷ�����λ�ã�ɾ���˸ýڵ�
 * 3. �������ӽڵ㶼�У���������ת�Ƶ���������������ڵ���������ϣ�Ȼ��������������λ��
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            // ������ɾ��
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // ������ɾ��
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                // �ڵ�������
                return root->right;
            } else if (root->right == nullptr) {
                // �ڵ����Һ���
                return root->left;
            } else {
                // �ڵ������Һ���
                TreeNode* cur = root->right;
                while (cur->left != nullptr) cur = cur->left;
                cur->left = root->left;
                root = root->right;
            }
        }
        return root;
    }
};