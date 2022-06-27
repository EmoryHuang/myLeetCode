/*
 * @Descroption: LeetCode 508. 出现次数最多的子树元素和
 * @Author: EmoryHuang
 * @Date: 2022-06-19 11:13:14
 * @Method:
 * 使用dfs计算子树元素和
 * 哈希表统计子树元素和出现次数
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
    unordered_map<int, int> map;
    int maxCnt = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        map[sum]++;
        maxCnt = max(maxCnt, map[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto& i : map) {
            if (i.second == maxCnt) res.push_back(i.first);
        }
        return res;
    }
};