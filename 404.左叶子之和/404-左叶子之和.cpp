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
    int ans=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL) return 0;
        int ans = 0;
        if(root->left && root->left->left==NULL &&root->left->right==NULL)
            ans +=root->left->val;
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right)+ans;
    }
};