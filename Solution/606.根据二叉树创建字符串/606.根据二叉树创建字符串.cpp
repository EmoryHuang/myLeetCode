/*
 * @Descroption: LeetCode 606. 根据二叉树创建字符串
 * @Author: EmoryHuang
 * @Date: 2021-04-28 14:13:36
 * @解题思路:
 * 二叉树 `[root,left,right]`，则转换为 `root(left)(right)`。
 * 如果只有 `left` 为空节点，则输出 `root()(right)`;
 * 如果只有 `right` 为空节点则可以忽略右节点的 `()`，输出为 `root(left)`
 */

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
        if (t == NULL) return "";
        if (t->left == NULL && t->right == NULL) return to_string(t->val);
        string left = tree2str(t->left);
        string right = tree2str(t->right);
        return to_string(t->val) + "(" + left + ")" + (t->right == NULL ? "" : "(" + right + ")");
    }
};