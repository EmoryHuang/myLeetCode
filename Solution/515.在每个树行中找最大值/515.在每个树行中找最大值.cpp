/*
 * @Descroption: LeetCode 515. ��ÿ�������������ֵ
 * @Author: EmoryHuang
 * @Date: 2021-05-30 18:10:00
 * @����˼·:
 * �Զ��������в��������Ѱ��ÿ������ֵ
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
    vector<int> largestValues(TreeNode *root) {
        if (root == nullptr) return {};
        queue<TreeNode *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty()) {
            int maxl = INT_MIN;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
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