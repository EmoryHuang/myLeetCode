/*
 * @Descroption: 剑指 Offer II 045. 二叉树最底层最左边的值
 * @Author: EmoryHuang
 * @Date: 2021-08-04 20:06:53
 * @Method:
 * 层序遍历，每遍历一层，则更新每层的第一个端点
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int ans = root->val;
        while (!q.empty()) {
            int n = q.size();
            bool flag = false;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (!flag) {
                    ans = node->val;
                    flag = true;
                }
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return ans;
    }
};