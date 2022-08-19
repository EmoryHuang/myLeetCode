/*
 * @Descroption: LeetCode 958. 二叉树的完全性检验
 * @Author: EmoryHuang
 * @Date: 2021-07-10 14:28:43
 * @解题思路:
 * 二叉树层序遍历，如果遇到空节点，则后面的遍历就不应该右节点了
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false; // flag 标识是否遇到空节点
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) { // 如果当前节点为空
                flag = true;
                continue;
            }
            if (flag) return false;
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};