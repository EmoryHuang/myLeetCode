/*
 * @Descroption: LeetCode 98. 验证二叉搜索树
 * @Author: EmoryHuang
 * @Date: 2021-03-27 12:33:36
 * @解题思路: 通过中序遍历，判断是否为升序序列
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
    TreeNode* pre = nullptr;  //前一个结点
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        if (!isValidBST(root->left)) return false;       //访问左子树
        if (pre && root->val <= pre->val) return false;  //若当前结点小于等于前一个结点
        pre = root;
        if (!isValidBST(root->right)) return false;  //访问右子树
        return true;
    }
};