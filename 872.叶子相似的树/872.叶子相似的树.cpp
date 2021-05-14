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
    void preOrder(TreeNode* root, vector<int>& leaf){
        if(root==nullptr) return;
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return;
        }
        preOrder(root->left,leaf);
        preOrder(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1,leaf2;
        preOrder(root1,leaf1);
        preOrder(root2,leaf2);
        if(leaf1.size()!=leaf2.size())return false;
        for(int i=0;i<leaf1.size();i++)
            if(leaf1[i]!=leaf2[i]) return false;
        return true;
    }
};