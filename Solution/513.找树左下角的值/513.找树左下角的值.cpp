/*
 * @Descroption: LeetCode 513. �������½ǵ�ֵ
 * @Author: EmoryHuang
 * @Date: 2021-05-30 18:18:00
 * @����˼·:
 * �Զ��������в������
 * ��Ϊ�ǲ������������ÿ�β�ĵ�һ����Ȼ������ߵĽڵ�
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
    int findBottomLeftValue(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node;
        while (!q.empty()) {
            node = q.front();
            q.pop();
            if (node->right) q.push(node->right);
            if (node->left) q.push(node->left);
        }
        return node->val;
    }
};