/*
 * @Descroption: LeetCode 111. ����������С���
 * @Author: EmoryHuang
 * @Date: 2021-05-09 15:34:36
 * @����˼·: �����������������ƣ�����������˹�����Ⱥ�����������ַ�����
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
    // ����һ���������
    int minDepth(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<TreeNode *> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            ans++;
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (!node->left && !node->right) {  // Ҷ�ӽڵ�
                    return ans;                     //���ص�ǰ���
                }
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
        }
        return ans;
    }

    // ���������������
    // int minDepth(TreeNode *root) {
    //     if (root == nullptr) return 0;
    //     if (!root->left && !root->right) return 1;
    //     int ans = INT_MAX;
    //     if (root->left) ans = min(ans, minDepth(root->left));
    //     if (root->right) ans = min(ans, minDepth(root->right));
    //     return ans + 1;
    // }
};