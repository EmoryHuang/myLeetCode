/*
 * @Descroption: LeetCode 863. 二叉树中所有距离为 K 的结点
 * @Author: EmoryHuang
 * @Date: 2021-07-28 13:44:26
 * @Method:
 * 由于每个节点的值都不相同，因此我们可以使用哈希表记录每个节点的父节点
 * 然后从目标节点出发，进行深度优先遍历，从三个方向上进行搜索
 * 找到深度为k的节点
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