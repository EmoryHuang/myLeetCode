/*
 * @Descroption: 剑指 Offer 34. 二叉树中和为某一值的路径
 * @Author: EmoryHuang
 * @Date: 2021-07-03 15:12:47
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
    void dfs(TreeNode *root, int target) {
        if (root == nullptr) return;
        way.push_back(root->val);
        // 当前结点为叶子节点，且路径总和等于给定目标和
        if (!root->left && !root->right && root->val == target) {
            ans.push_back(way);  // 把这条路径加入到 ans
        }
        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);
        way.pop_back();  // 撤销选择
    }
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        dfs(root, target);
        return ans;
    }
};