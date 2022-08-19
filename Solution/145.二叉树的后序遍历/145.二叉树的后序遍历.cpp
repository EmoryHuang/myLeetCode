/*
 * @Descroption: LeetCode 145. 二叉树的后序遍历
 * @Author: EmoryHuang
 * @Date: 2021-05-17 15:39:26
 * @解题思路:
 * 方法一：递归
 * 简单的后序遍历
 *
 * 方法二：迭代
 * 与递归的方法类似，只不过迭代维护了一个栈
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

    // 方法二：迭代
    vector<int> postorderTraversal(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> ans;
        stack<TreeNode *> s;
        TreeNode *pre = nullptr;
        while (!s.empty() || root) {
            while (root) {  //若存在左孩子，则入栈
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            // 如果右孩子为空或者右子已访问
            if (root->right == nullptr || root->right == pre) {
                ans.push_back(root->val);
                pre = root;
                root = nullptr;
            } else {  //若存在右孩子，则入栈
                s.push(root);
                root = root->right;
            }
        }
        return ans;
    }
};