/*
 * @Descroption: LeetCode 623. 在二叉树中增加一行
 * @Author: EmoryHuang
 * @Date: 2021-08-16 19:44:55
 * @Method:
 * 层序遍历，遍历到 depth - 1 层时，添加新的节点
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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        queue<TreeNode*> q;
        q.push(root);
        int cur_depth = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (cur_depth == depth - 1) {
                    TreeNode* tmpl = node->left;
                    node->left = new TreeNode(val);
                    node->left->left = tmpl;

                    TreeNode* tmpr = node->right;
                    node->right = new TreeNode(val);
                    node->right->right = tmpr;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cur_depth++;
        }
        return root;
    }
};