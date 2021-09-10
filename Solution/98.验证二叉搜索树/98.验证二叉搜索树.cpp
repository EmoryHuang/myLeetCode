/*
 * @Descroption: LeetCode 98. ��֤����������
 * @Author: EmoryHuang
 * @Date: 2021-03-27 12:33:36
 * @����˼·: ͨ������������ж��Ƿ�Ϊ��������
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
    TreeNode* pre = nullptr;  //ǰһ�����
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isValidBST(root->left)) return false;       //����������
        if (pre && root->val <= pre->val) return false;  //����ǰ���С�ڵ���ǰһ�����
        pre = root;
        if (!isValidBST(root->right)) return false;  //����������
        return true;
    }
};