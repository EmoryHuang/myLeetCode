/*
 * @Descroption: 剑指 Offer 32 - I. 从上到下打印二叉树
 * @Author: EmoryHuang
 * @Date: 2021-07-03 13:35:02
 * @解题思路:
 * 按照层序遍历的方法打印即可
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
    vector<int> levelOrder(TreeNode *root) {
        if (!root) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            ans.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        return ans;
    }
};