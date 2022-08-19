/*
 * @Descroption: LeetCode 102. 二叉树的层序遍历
 * @Author: EmoryHuang
 * @Date: 2021-04-18 14:54:36
 * @解题思路: 基础题，层序遍历，使用队列实现
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> tmp;
            int len = q.size();
            for (int i = 0; i < len; i++) {  //遍历每层的元素
                TreeNode* node = q.front();
                q.pop();
                tmp.push_back(node->val);  // 加入临时向量
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};