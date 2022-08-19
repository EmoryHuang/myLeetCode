/*
 * @Descroption: LeetCode 1609. 奇偶树
 * @Author: EmoryHuang
 * @Date: 2021-07-24 14:09:29
 * @解题思路:
 * 广度优先遍历
 * 记录节点深度，记录前一个节点的大小
 * 判断是否出现深度为偶且节点不为奇或不严格递增，深度为奇且节点不为偶或不严格递减
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
    bool isEvenOddTree(TreeNode* root) {
        int deep = 0, preo, pree;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            preo = -1;
            pree = INT_MAX;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (deep % 2 == 0) {
                    if (node->val % 2 == 0 || node->val <= preo) return false;
                } else {
                    if (node->val % 2 == 1 || node->val >= pree) return false;
                }
                pree = preo = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            deep++;
        }
        return true;
    }
};