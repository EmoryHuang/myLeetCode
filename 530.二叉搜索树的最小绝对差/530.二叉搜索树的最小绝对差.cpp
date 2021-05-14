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
    int ans = INT_MAX;
    TreeNode *pre = nullptr;
    void dfs(TreeNode* root){
        if(root==nullptr) return;
        dfs(root->left);
        if(pre != nullptr)
            ans = min(root->val-pre->val,ans);
        pre= root;
        dfs(pre->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return ans;
    }
};