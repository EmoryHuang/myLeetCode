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
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};