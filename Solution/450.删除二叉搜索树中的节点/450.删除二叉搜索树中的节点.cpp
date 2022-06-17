/*
 * @Descroption: LeetCode 450. 删除二叉搜索树中的节点
 * @Author: EmoryHuang
 * @Date: 2022-06-02 09:10:54
 * @Method:
 * 递归
 * 如果目标节点大于当前节点值，则去右子树中删除，否则去左子树中删除
 * 如果目标节点就是当前节点：
 * 1. 其无左子：其右子顶替其位置，删除了该节点
 * 2. 其无右子：其左子顶替其位置，删除了该节点
 * 3. 其左右子节点都有：其左子树转移到其右子树的最左节点的左子树上，然后右子树顶替其位置
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val > key) {
            // 左子树删除
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            // 右子树删除
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                // 节点无左孩子
                return root->right;
            } else if (root->right == nullptr) {
                // 节点无右孩子
                return root->left;
            } else {
                // 节点有左右孩子
                TreeNode* cur = root->right;
                while (cur->left != nullptr) cur = cur->left;
                cur->left = root->left;
                root = root->right;
            }
        }
        return root;
    }
};