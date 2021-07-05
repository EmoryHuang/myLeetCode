/*
 * @Descroption: ��ָ Offer 55 - I. �����������
 * @Author: EmoryHuang
 * @Date: 2021-07-05 22:25:40
 * @����˼·:
 * ����һ���ݹ�
 * ���������������˼·
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
    // ����һ���ݹ�
    // int maxDepth(TreeNode* root) {
    //     return root == nullptr ? 0 : 1 + max(maxDepth(root->left), maxDepth(root->right));
    // }

    // ���������������
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            ans++;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};