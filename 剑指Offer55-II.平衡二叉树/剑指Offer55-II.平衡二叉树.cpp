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
    int balance(TreeNode *root) {
        if (root == nullptr) return 0;
        int left = balance(root->left);
        int right = balance(root->right);
        if (left >= 0 && right >= 0 && abs(left - right) <= 1)
            return max(left, right) + 1;
        else
            return -1;  // -1表示不平衡
    }
    bool isBalanced(TreeNode *root) { return balance(root) >= 0; }
};