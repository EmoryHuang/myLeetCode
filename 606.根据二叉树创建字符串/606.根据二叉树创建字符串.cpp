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
    string tree2str(TreeNode* t) {
        if(t==NULL) return "";
        if(t->left==NULL && t->right==NULL) return to_string(t->val);
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        return to_string(t->val) + "(" + left +")"+(t->right==NULL?"":"("+right+")");
    }
};