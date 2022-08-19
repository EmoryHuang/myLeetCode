/*
 * @Descroption: 剑指 Offer 54. 二叉搜索树的第k大节点
 * @Author: EmoryHuang
 * @Date: 2021-10-18 19:28:55
 * @Method:
 * 方法一：中序遍历
 * 二叉搜索树中序遍历之后就是有序数列，取第 n - k 个元素即可
 *
 * 方法二：中序遍历 + 剪枝
 * 中序遍历只需要遍历到第 k 个元素
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
    // vector<int> nums;
    // void inorder(TreeNode* node) {
    //     if (node) {
    //         inorder(node->left);
    //         nums.push_back(node->val);
    //         inorder(node->right);
    //     }
    // }
    // int kthLargest(TreeNode* root, int k) {
    //     inorder(root);
    //     return nums[nums.size() - k];
    // }

    // 方法二：中序遍历 + 剪枝
    int ans = 0, cnt = 0;
    void inorder(TreeNode* node, int k) {
        if (node) {
            inorder(node->right, k);
            if (++cnt == k) ans = node->val;
            inorder(node->left, k);
        }
    }
    int kthLargest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};