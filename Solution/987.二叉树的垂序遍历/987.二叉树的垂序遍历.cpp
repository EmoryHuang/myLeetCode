/*
 * @Descroption: LeetCode 987. �������Ĵ������
 * @Author: EmoryHuang
 * @Date: 2021-07-31 13:31:53
 * @Method:
 * dfs + ����
 * dfs �õ����нڵ�����꣬Ȼ��������
 * ����ͬ�кŵ�Ԫ�ط���ͬһ����
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
    vector<tuple<int, int, int>> nodes;
    void dfs(TreeNode* node, int x, int y) {
        if (!node) return;
        nodes.emplace_back(y, x, node->val);
        dfs(node->left, x + 1, y - 1);
        dfs(node->right, x + 1, y + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        // dfs �õ����нڵ������
        dfs(root, 0, 0);
        // ��������
        sort(nodes.begin(), nodes.end());
        int precol = INT_MIN;  // ǰһ���ڵ����
        for (auto [y, x, val] : nodes) {
            // �������ͬһ��
            if (y != precol) {
                precol = y;
                ans.emplace_back();
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};