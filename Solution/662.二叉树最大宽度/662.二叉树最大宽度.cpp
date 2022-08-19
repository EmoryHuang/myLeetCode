/*
 * @Descroption: LeetCode 662. �����������
 * @Author: EmoryHuang
 * @Date: 2021-05-24 19:52:11
 * @����˼·:
 * ���ö��������������˼·����¼ÿ��Ľڵ���
 * ������ʹ��int��¼���index
 * �������Ǹ��ڵ�� index * 2,�������� index * 2 + 1
 * Ȼ���ȥ start * 2 �����ڸò�Ľڵ������
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
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            int ind = 0, start = q.front().second;  // start�Ǳ������
            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front().first;
                ind = q.front().second;  // ��ǰ�ڵ���
                q.pop();
                // ��ȥͬһ��ڵ�����ߵ�ֵ
                if (node->left) q.push({node->left, ind * 2 - start * 2});
                if (node->right) q.push({node->right, ind * 2 + 1 - start * 2});
            }
            ans = max(ans, ind - start + 1);
        }
        return ans;
    }
};