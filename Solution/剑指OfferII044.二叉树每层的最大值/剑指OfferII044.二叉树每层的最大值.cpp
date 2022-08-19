/*
 * @Descroption: 剑指 Offer II 044. 二叉树每层的最大值
 * @Author: EmoryHuang
 * @Date: 2021-08-04 19:58:25
 * @Method:
 * 层序遍历，记录每层的最大值
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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            int maxl = INT_MIN;
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                q.pop();
                maxl = max(maxl, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            ans.push_back(maxl);
        }
        return ans;
    }
};