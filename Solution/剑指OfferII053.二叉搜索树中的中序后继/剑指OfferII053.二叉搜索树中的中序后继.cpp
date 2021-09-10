/*
 * @Descroption: 剑指 Offer II 053. 二叉搜索树中的中序后继
 * @Author: EmoryHuang
 * @Date: 2021-09-08 15:51:12
 * @Method:
 * 方法一：中序遍历
 * 中序遍历，记录节点的前驱，中序遍历找到指定节点后的下一个节点
 *
 * 方法二：二叉搜索树的性质
 * 若当前节点的值小于等于节点 p 的值，那么节点 p 的下一个节点应该在当前节点的右子树
 * 若当前节点的值大于节点 p 的值，那么当前节点就有可能是节点 p 的下一个节点
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
    // 方法一：中序遍历
    // TreeNode* pre = nullptr;
    // TreeNode* ans = nullptr;
    // void inorder(TreeNode* root, TreeNode* p) {
    //     if (!root) return;
    //     inorder(root->left, p);
    //     if (pre == p) ans = root;
    //     pre = root;
    //     inorder(root->right, p);
    // }
    // TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    //     inorder(root, p);
    //     return ans;
    // }

    // 方法二：二叉搜索树的性质
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* ans = nullptr;
        while (root) {
            // 若当前节点值大于节点 p
            if (root->val > p->val) {
                ans = root;
                // 向左寻找更小的元素
                root = root->left;
            } else
                // 向右寻找更大的元素
                root = root->right;
        }
        return ans;
    }
};