/*
 * @Descroption: LeetCode 337. 打家劫舍 III
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:22:48
 * @解题思路:
 * 如果是偷当前节点，那么左右孩子就不能偷
 * 如果是不偷当前节点，那么左右孩子可偷可不偷，取最大值
 * 当前节点的状态就是 (偷的金额，不偷的金额)
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};  // (偷的金额，不偷的金额)
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        // 0 表示偷，1表示不偷
        // 偷当前节点，不偷子节点
        int val1 = root->val + left[1] + right[1];
        // 不偷当前节点，不偷/偷子节点
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val1, val2};
    }
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};