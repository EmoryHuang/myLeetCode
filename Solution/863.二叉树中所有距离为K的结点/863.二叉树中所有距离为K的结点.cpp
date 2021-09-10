/*
 * @Descroption: LeetCode 863. �����������о���Ϊ K �Ľ��
 * @Author: EmoryHuang
 * @Date: 2021-07-28 13:44:26
 * @Method:
 * ����ÿ���ڵ��ֵ������ͬ��������ǿ���ʹ�ù�ϣ���¼ÿ���ڵ�ĸ��ڵ�
 * Ȼ���Ŀ��ڵ����������������ȱ����������������Ͻ�������
 * �ҵ����Ϊk�Ľڵ�
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
    unordered_map<int, TreeNode*> parents;
    vector<int> ans;
    void find_parent(TreeNode* node) {
        if (node->left) {
            parents[node->left->val] = node;
            find_parent(node->left);
        }
        if (node->right) {
            parents[node->right->val] = node;
            find_parent(node->right);
        }
    }
    void find_deep_k(TreeNode* node, TreeNode* parent, int depth, int k) {
        if (!node) return;
        if (depth == k) {
            ans.push_back(node->val);
            return;
        }
        if (node->left != parent) find_deep_k(node->left, node, depth + 1, k);
        if (node->right != parent) find_deep_k(node->right, node, depth + 1, k);
        if (parents[node->val] != parent) find_deep_k(parents[node->val], node, depth + 1, k);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        find_parent(root);
        find_deep_k(target, nullptr, 0, k);
        return ans;
    }
};