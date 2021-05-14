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
    bool isSameTree(TreeNode* s, TreeNode* t){
        if(s==nullptr && t==nullptr)return true;
        return s && t&& s->val == t->val && isSameTree(s->left,t->left)&&isSameTree(s->right,t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr && t==nullptr)return true;
        if(s==nullptr && t!=nullptr) return false;
        return isSameTree(s,t) || isSubtree(s->left,t) || isSubtree(s->right,t);
        
    }
};