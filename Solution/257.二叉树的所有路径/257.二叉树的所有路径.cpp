/*
 * @Descroption: LeetCode 257. 二叉树的所有路径
 * @Author: EmoryHuang
 * @Date: 2021-05-17 16:30:26
 * @解题思路:
 * 深度优先，遍历每条路径
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
    void dfs(TreeNode *root, vector<string> &ans, string path) {
        if (root == nullptr) return;
        path += to_string(root->val);
        if (!root->left && !root->right) {
            ans.push_back(path);
            return;
        }
        dfs(root->left, ans, path + "->");
        dfs(root->right, ans, path + "->");
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ans;
        if (root == nullptr) return ans;
        dfs(root, ans, "");
        return ans;
    }
};