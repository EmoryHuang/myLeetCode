/*
 * @Descroption: LeetCode 1302. 层数最深叶子节点的和
 * @Author: EmoryHuang
 * @Date: 2021-07-19 19:13:36
 * @解题思路:
 * 层序遍历，计算每层的节点之和
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
    int deepestLeavesSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;
        while (!q.empty()) {
            int n = q.size();
            ans = 0;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                ans += node->val;
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};