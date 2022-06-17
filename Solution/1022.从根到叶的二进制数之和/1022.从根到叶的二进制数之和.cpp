/*
 * @Descroption: LeetCode 1022. �Ӹ���Ҷ�Ķ�������֮��
 * @Author: EmoryHuang
 * @Date: 2022-05-30 12:44:27
 * @Method:
 * dfs
 * ���⣬dfs ����ÿ��·���ĺ�
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
    int dfs(TreeNode* node, int cur) {
        if (node == nullptr) return 0;
        cur = cur << 1 | node->val;
        // �����Ҷ�ӽ�㣬�򷵻�·���ϵ�ֵ
        if (node->left == nullptr && node->right == nullptr) return cur;
        // �ݹ�
        return dfs(node->left, cur) + dfs(node->right, cur);
    }
    int sumRootToLeaf(TreeNode* root) { return dfs(root, 0); }
};