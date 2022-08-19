/*
 * @Descroption: LeetCode 230. 二叉搜索树中第K小的元素
 * @Author: EmoryHuang
 * @Date: 2021-10-17 13:01:24
 * @Method:
 * 方法一：中序遍历
 * 二叉搜索树中序遍历之后就是有序数列，取第 k - 1 个元素即可
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
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    // int kthSmallest(TreeNode* root, int k) {
    //     dfs(root);
    //     return nums[k - 1];
    // }

    // 方法二：中序遍历 + 剪枝
    int ans = 0;
    int _k = 0;
    void inorder(TreeNode* node) {
        if (node && _k > 0) {
            inorder(node->left);
            if (--_k == 0) ans = node->val;
            inorder(node->right);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        _k = k;
        inorder(root);
        return ans;
    }
};