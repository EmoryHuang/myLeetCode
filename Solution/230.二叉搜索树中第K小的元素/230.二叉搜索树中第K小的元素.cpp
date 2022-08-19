/*
 * @Descroption: LeetCode 230. �����������е�KС��Ԫ��
 * @Author: EmoryHuang
 * @Date: 2021-10-17 13:01:24
 * @Method:
 * ����һ���������
 * �����������������֮������������У�ȡ�� k - 1 ��Ԫ�ؼ���
 *
 * ��������������� + ��֦
 * �������ֻ��Ҫ�������� k ��Ԫ��
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
    // ����һ���������
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

    // ��������������� + ��֦
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