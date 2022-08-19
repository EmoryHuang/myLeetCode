/*
 * @Descroption: LeetCode 114. 二叉树展开为链表
 * @Author: EmoryHuang
 * @Date: 2021-05-14 16:44:28
 * @解题思路: 依据二叉树展开为链表的特点，将先序遍历倒着来
 * 记录每次递归的最后一个结点，根节点的右指针指向last，左子树置空
 * 然后更新 last = root
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
    TreeNode* last = nullptr;  // last为最后一个结点
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = nullptr;  // 左子树置空
        last = root;           // 更新last
    }
};