/*
 * @Descroption: LeetCode 113. ·���ܺ� II
 * @Author: EmoryHuang
 * @Date: 2021-05-16 17:47:16
 * @����˼·:
 * ���ݷ�
 * ö��ÿһ���Ӹ��ڵ㵽Ҷ�ӽڵ��·��
 * ��������Ҷ�ӽڵ㣬�Ҵ�ʱ·����ǡΪĿ���ʱ�����ҵ���һ��·��
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
    vector<vector<int>> ans;
    vector<int> way;
    void dfs(TreeNode *root, int targetSum) {
        if (root == nullptr) return;
        way.push_back(root->val);
        // ��ǰ���ΪҶ�ӽڵ㣬��·���ܺ͵��ڸ���Ŀ���
        if (!root->left && !root->right && root->val == targetSum) {
            ans.push_back(way);  // ������·�����뵽 ans
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        way.pop_back();  // ����ѡ��
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};