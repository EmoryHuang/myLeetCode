/*
 * @Descroption: LeetCode 987. 二叉树的垂序遍历
 * @Author: EmoryHuang
 * @Date: 2021-07-31 13:31:53
 * @Method:
 * dfs + 排序
 * dfs 得到所有节点的坐标，然后按列排序
 * 像相同列号的元素放入同一矩阵
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
        // dfs 得到所有节点的坐标
        dfs(root, 0, 0);
        // 按列排列
        sort(nodes.begin(), nodes.end());
        int precol = INT_MIN;  // 前一个节点的列
        for (auto [y, x, val] : nodes) {
            // 如果不在同一列
            if (y != precol) {
                precol = y;
                ans.emplace_back();
            }
            ans.back().push_back(val);
        }
        return ans;
    }
};