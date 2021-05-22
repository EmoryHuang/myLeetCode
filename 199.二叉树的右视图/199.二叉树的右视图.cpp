/*
 * @Descroption: LeetCode 199. ������������ͼ
 * @Author: EmoryHuang
 * @Date: 2021-05-22 14:58:00
 * @����˼·:
 * ���ղ��������˼�룬��������������ÿһ������һ�����ʱ��������ֵ����ans
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
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) return {};
        queue<TreeNode *> q;
        vector<int> ans;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (i == n - 1) ans.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};