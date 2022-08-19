/*
 * @Descroption: LeetCode 662. 二叉树最大宽度
 * @Author: EmoryHuang
 * @Date: 2021-05-24 19:52:11
 * @解题思路:
 * 采用二叉树层序遍历的思路，记录每层的节点编号
 * 队列中使用int记录编号index
 * 左子树是父节点的 index * 2,右子树是 index * 2 + 1
 * 然后减去 start * 2 便是在该层的节点的数量
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
    int widthOfBinaryTree(TreeNode *root) {
        if (root == nullptr) return 0;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 1});
        int ans = 0;
        while (!q.empty()) {
            int len = q.size();
            int ind = 0, start = q.front().second;  // start是本层起点
            for (int i = 0; i < len; i++) {
                TreeNode *node = q.front().first;
                ind = q.front().second;  // 当前节点编号
                q.pop();
                // 减去同一层节点最左边的值
                if (node->left) q.push({node->left, ind * 2 - start * 2});
                if (node->right) q.push({node->right, ind * 2 + 1 - start * 2});
            }
            ans = max(ans, ind - start + 1);
        }
        return ans;
    }
};