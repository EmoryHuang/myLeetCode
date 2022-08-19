/*
 * @Descroption: LeetCode 572. ��һ����������
 * @Author: EmoryHuang
 * @Date: 2021-03-29 19:48:36
 * @����˼·:
 * һ��������һ��������������Ҫô����������ȣ�Ҫô�������������������Ҫô�����������������
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
        if (s == nullptr && t == nullptr) return true;  //��Ϊ�������
        return s && t && s->val == t->val && isSameTree(s->left, t->left) &&
               isSameTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;   //��Ϊ����������
        if (s == nullptr && t != nullptr) return false;  // sΪ��
        return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};