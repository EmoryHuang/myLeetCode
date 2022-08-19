/*
 * @Descroption: ��ָ Offer 34. �������к�Ϊĳһֵ��·��
 * @Author: EmoryHuang
 * @Date: 2021-07-03 15:12:47
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
    void dfs(TreeNode *root, int target) {
        if (root == nullptr) return;
        way.push_back(root->val);
        // ��ǰ���ΪҶ�ӽڵ㣬��·���ܺ͵��ڸ���Ŀ���
        if (!root->left && !root->right && root->val == target) {
            ans.push_back(way);  // ������·�����뵽 ans
        }
        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);
        way.pop_back();  // ����ѡ��
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};