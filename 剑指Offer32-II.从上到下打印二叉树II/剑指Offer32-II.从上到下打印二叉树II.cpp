/*
 * @Descroption: 剑指 Offer 32 - II. 从上到下打印二叉树 II
 * @Author: EmoryHuang
 * @Date: 2021-07-03 13:58:31
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};