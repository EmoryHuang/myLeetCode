/*
 * @Descroption: LeetCode 113. 路径总和 II
 * @Author: EmoryHuang
 * @Date: 2021-05-16 17:47:16
 * @解题思路:
 * 回溯法
 * 枚举每一条从根节点到叶子节点的路径
 * 若遍历到叶子节点，且此时路径和恰为目标和时，就找到了一条路径
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
        // 当前结点为叶子节点，且路径总和等于给定目标和
        if (!root->left && !root->right && root->val == targetSum) {
            ans.push_back(way);  // 把这条路径加入到 ans
        }
        dfs(root->left, targetSum - root->val);
        dfs(root->right, targetSum - root->val);
        way.pop_back();  // 撤销选择
    }
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};