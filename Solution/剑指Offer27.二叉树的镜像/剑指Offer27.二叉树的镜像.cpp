/*
 * @Descroption: ��ָ Offer 27. �������ľ���
 * @Author: EmoryHuang
 * @Date: 2021-07-02 15:05:00
 * @����˼·:
 * ʹ��һ����ʱ�ڵ㱣�棬Ȼ��ݹ�ؽ�����������
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
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};