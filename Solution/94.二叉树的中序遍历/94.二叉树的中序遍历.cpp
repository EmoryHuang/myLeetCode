/*
 * @Descroption: LeetCode 94. 二叉树的中序遍历
 * @Author: EmoryHuang
 * @Date: 2021-06-07 21:15:00
 * @解题思路:
 * 方法一：递归
 * 方法二：迭代
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
    // vector<int> ans;
    // void inorder(TreeNode *root) {
    //     if (root) {
    //         inorder(root->left);
    //         ans.push_back(root->val);
    //         inorder(root->right);
    //     }
    // }
    // vector<int> inorderTraversal(TreeNode *root) {
    //     inorder(root);
    //     return ans;
    // }

    // 方法二：迭代
    vector<int> inorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> ans;
        while (!s.empty() || root) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            TreeNode *cur = s.top();
            s.pop();
            ans.push_back(cur->val);
            root = cur->right;
        }
        return ans;
    }
};