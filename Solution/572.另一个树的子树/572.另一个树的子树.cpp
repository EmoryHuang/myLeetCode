/*
 * @Descroption: LeetCode 572. 另一个树的子树
 * @Author: EmoryHuang
 * @Date: 2021-03-29 19:48:36
 * @解题思路:
 * 一个树是另一个树的子树，则要么这两个树相等，要么这个树是左树的子树，要么这个树是右树的子树
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
    bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;  //都为空则相等
        return s && t && s->val == t->val && isSameTree(s->left, t->left) &&
               isSameTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;   //都为空则是子树
        if (s == nullptr && t != nullptr) return false;  // s为空
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};