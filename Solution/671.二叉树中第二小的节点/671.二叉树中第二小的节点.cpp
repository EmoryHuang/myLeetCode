/*
 * @Descroption: LeetCode 671. �������еڶ�С�Ľڵ�
 * @Author: EmoryHuang
 * @Date: 2021-07-27 13:51:29
 * @Method:
 * ���ڵ�һ��С�ڵ��������ӽڵ㣬�������ĸ��ڵ�Ϊ��С�Ľڵ�
 * ��ô��Ŀ�ͱ������������������С�Ľڵ�
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
    int dfs(TreeNode* node, int val) {
        if (node == nullptr) return -1;
        if (node->val > val) return node->val;
        int l = dfs(node->left, val);
        int r = dfs(node->right, val);
        if (l > val && r > val) return min(l, r);
        return max(l, r);
    }
    int findSecondMinimumValue(TreeNode* root) { return dfs(root, root->val); }
};