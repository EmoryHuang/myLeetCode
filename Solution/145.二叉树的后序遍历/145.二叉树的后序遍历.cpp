/*
 * @Descroption: LeetCode 145. �������ĺ������
 * @Author: EmoryHuang
 * @Date: 2021-05-17 15:39:26
 * @����˼·:
 * ����һ���ݹ�
 * �򵥵ĺ������
 *
 * ������������
 * ��ݹ�ķ������ƣ�ֻ��������ά����һ��ջ
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
    // ����һ���ݹ�
    // vector<int> ans;
    // void postorder(TreeNode *root) {
    //     if (root == nullptr) return;
    //     postorder(root->left);
    //     postorder(root->right);
    //     ans.push_back(root->val);
    // }
    // vector<int> postorderTraversal(TreeNode *root) {
    //     postorder(root);
    //     return ans;
    // }

    // ������������
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        while (!s.empty() || root) {
            while (root) {  //���������ӣ�����ջ
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            // ����Һ���Ϊ�ջ��������ѷ���
            if (root->right == nullptr || root->right == pre) {
                ans.push_back(root->val);
                pre = root;
                root = nullptr;
            } else {  //�������Һ��ӣ�����ջ
                s.push(root);
                root = root->right;
            }
        }
        return ans;
    }
};