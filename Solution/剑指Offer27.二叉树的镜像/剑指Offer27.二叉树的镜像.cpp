/*
 * @Descroption: 剑指 Offer 27. 二叉树的镜像
 * @Author: EmoryHuang
 * @Date: 2021-07-02 15:05:00
 * @解题思路:
 * 使用一个临时节点保存，然后递归地交换左右子树
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* mirrorTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* tmp = root->left;
        root->left = mirrorTree(root->right);
        root->right = mirrorTree(tmp);
        return root;
    }
};