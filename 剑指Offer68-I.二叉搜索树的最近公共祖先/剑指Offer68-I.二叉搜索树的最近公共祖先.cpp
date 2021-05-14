/*
 * @Descroption: LeetCode 235. �����������������������
 * @Author: EmoryHuang
 * @Date: 2021-04-02 19:04:36
 * @����˼·:
 * ���ö��������������ʣ��� `p` �� `q` λ�� `root` ������ʱ��ֱ�ӷ��أ�
 * �� `p` �� `q` λ�� `root` ��ͬ��ʱ��������������
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
    // ����һ���ݹ�
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) return NULL;
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);  // p �� q ������������
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);  // p �� q ������������
        return root;
    }

    // ������������
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
