/*
 * @Descroption: LeetCode 1161. 最大层内元素和
 * @Author: EmoryHuang
 * @Date: 2021-05-26 17:17:17
 * @解题思路:
 * 利用层序遍历的思想
 * 维护变量 depth 代表当前深度，计算每层的元素之和
 * 返回层内元素之和最大的层号
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
    int maxLevelSum(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        int maxSum = INT_MIN;
        int depth = 0, ans = 0;  // depth记录层号
        while (!q.empty()) {
            int n = q.size();
            depth++;
            int sum = 0;  // 当前层内元素之和
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;  // 更新最大层内元素之和
                ans = depth;   // 更新层号
            }
        }
        return ans;
    }
};