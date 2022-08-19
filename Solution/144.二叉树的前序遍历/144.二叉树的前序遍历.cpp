/*
 * @Descroption: LeetCode 144. ��������ǰ�����
 * @Author: EmoryHuang
 * @Date: 2021-03-26 16:23:36
 * @����˼·: �ݹ鷽���ܼ򵥣�����������Ҫʹ��ջ
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
    void preorder(TreeNode* root, vector<int>& ans) {
        if (root) {
            ans.push_back(root->val);
            preorder(root->left, ans);
            preorder(root->right, ans);
        }
    }

    // ������������
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while (!st.empty()) {
    //         TreeNode* node = st.top();
    //         st.pop();
    //         if (node) {  //�ǿ�
    //             ans.push_back(node->val);
    //             st.push(node->right);  //ջ�Ǻ���ȳ��������ȼ������ӽڵ�
    //             st.push(node->left);
    //         }
    //     }
    //     return ans;
    // }
};