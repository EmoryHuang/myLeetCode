/*
 * @Descroption: ��ָ Offer 54. �����������ĵ�k��ڵ�
 * @Author: EmoryHuang
 * @Date: 2021-10-18 19:28:55
 * @Method:
 * ����һ���������
 * �����������������֮������������У�ȡ�� n - k ��Ԫ�ؼ���
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    // int kthLargest(TreeNode* root, int k) {
    //     inorder(root);
    //     return nums[nums.size() - k];
    // }

    // ��������������� + ��֦
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