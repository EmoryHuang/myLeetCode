/*
 * @Descroption: LeetCode 144. 二叉树的前序遍历
 * @Author: EmoryHuang
 * @Date: 2021-03-26 16:23:36
 * @解题思路: 递归方法很简单，迭代方法需要使用栈
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
    // 方法一：递归
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

    // 方法二：迭代
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     stack<TreeNode*> st;
    //     st.push(root);
    //     while (!st.empty()) {
    //         TreeNode* node = st.top();
    //         st.pop();
    //         if (node) {  //非空
    //             ans.push_back(node->val);
    //             st.push(node->right);  //栈是后进先出，所以先加入右子节点
    //             st.push(node->left);
    //         }
    //     }
    //     return ans;
    // }
};