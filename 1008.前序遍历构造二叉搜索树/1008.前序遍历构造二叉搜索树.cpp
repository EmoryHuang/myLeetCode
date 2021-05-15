/*
 * @Descroption: LeetCode 1008. ǰ������������������
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:20:36
 * @����˼·:
 * ͨ���ݹ鲢�жϽ���С����
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
    TreeNode* build(TreeNode* root, int num) {
        if (root == nullptr) return new TreeNode(num);
        if (root->val > num)
            root->left = build(root->left, num);
        else
            root->right = build(root->right, num);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = nullptr;
        for (int i = 0; i < preorder.size(); i++) {
            root = build(root, preorder[i]);
        }
        return root;
    }
};