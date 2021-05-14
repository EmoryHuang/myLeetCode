/*
 * @Descroption: LeetCode 235. 二叉搜索树的最近公共祖先
 * @Author: EmoryHuang
 * @Date: 2021-04-02 19:04:36
 * @解题思路:
 * 利用二叉搜索树的性质，当 `p` 和 `q` 位于 `root` 的两侧时，直接返回，
 * 当 `p` 和 `q` 位于 `root` 的同侧时，继续向下搜索
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
    // 方法一：递归
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);  // p 和 q 都在左子树上
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);  // p 和 q 都在右子树上
        return root;
    }

    // 方法二：迭代
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     while (root) {
    //         if (root->val > p->val && root->val > q->val)
    //             root = root->left;
    //         else if (root->val < p->val && root->val < q->val)
    //             root = root->right;
    //         else
    //             return root;
    //     }
    //     return NULL;
    // }
};
