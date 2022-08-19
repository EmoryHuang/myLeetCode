/*
 * @Descroption: 剑指 Offer 07. 重建二叉树
 * @Author: EmoryHuang
 * @Date: 2021-06-28 19:56:00
 * @解题思路:
 * 根据中序遍历和先序遍历重建二叉树
 * 采用递归的方法
 * 先序遍历的最左边的节点是根节点，
 * 然后再到中序遍历中找到根节点的位置，它将左右子树一分为二
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
    unordered_map<int, int> map;
    TreeNode* build(vector<int>& preorder, int pre_l, int pre_r, vector<int>& inorder, int in_l,
                    int in_r) {
        if (pre_l > pre_r || in_l > in_r) return nullptr;
        // 根节点在前序遍历中的位置
        int pre_root = pre_l;
        // 根节点在中序遍历中的位置
        int in_root = map[preorder[pre_root]];
        TreeNode* root = new TreeNode(preorder[pre_root]);
        // 左子树节点个数
        int left_size = in_root - in_l;

        root->left = build(preorder, pre_l + 1, pre_l + left_size, inorder, in_l, in_root - 1);
        root->right = build(preorder, pre_l + left_size + 1, pre_r, inorder, in_root + 1, in_r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) map[inorder[i]] = i;
        return build(preorder, 0, n - 1, inorder, 0, n - 1);
    }
};