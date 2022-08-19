/*
 * @Descroption: LeetCode 538. 把二叉搜索树转换为累加树
 * @Author: EmoryHuang
 * @Date: 2021-05-30 18:26:00
 * @解题思路:
 * 反序中序遍历该二叉搜索树，记录过程中的节点值之和，
 * 并不断更新当前遍历到的节点的节点值
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
    int pre = 0;
    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr) return nullptr;
        convertBST(root->right);  // 遍历右子树
        root->val += pre;         // 更新节点值
        pre = root->val;
        convertBST(root->left);  // 遍历左子树
        return root;
    }
};