/*
 * @Descroption: LeetCode 993. 二叉树的堂兄弟节点
 * @Author: EmoryHuang
 * @Date: 2021-05-17 14:43:26
 * @解题思路:
 * 方法一：BFS
 * 通过层次遍历的方法创建队列，队列中的结点为 pair，first 存储当前结点，second 存储父节点
 * 由于二叉树具有唯一值，因此当读到 x 或者 y 时将其父节点加入 parent
 * 每遍历完一层，判断是否 parent[0] != parent[1]
 * 若只出现了一个值，则表明不在同一层
 *
 * 方法二：DFS
 * 通过深度优先遍历树，若读到x或者y,记录x,y的深度和父节点
 * 最后判断深度是否相等，父节点是否不同
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
    // 方法一：BFS
    bool isCousins(TreeNode *root, int x, int y) {
        // first 存储当前结点，second 存储父节点
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            int len = q.size();
            vector<TreeNode *> parent;  // 记录父节点
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                TreeNode *cur = node.first;
                TreeNode *pre = node.second;
                q.pop();
                if (cur->val == x || cur->val == y) parent.push_back(pre);
                if (cur->left) q.push({cur->left, cur});
                if (cur->right) q.push({cur->right, cur});
            }
            if (parent.size() == 1)  // 只出现了一个值，不在同一层
                return false;
            else if (parent.size() == 2)
                return parent[0] != parent[1];  // 判断父节点
        }
        return false;
    }

    // 方法二：DFS
    // int depth1 = 0, depth2 = 0;  // 分别记录结点的深度和父节点的值
    // TreeNode *pre1 = nullptr, *pre2 = nullptr;
    // void dfs(TreeNode *root, int depth, TreeNode *pre, int x, int y) {
    //     if (root == nullptr) return;
    //     if (root->val == x) {
    //         depth1 = depth;  // 更新深度
    //         pre1 = pre;      // 更新父节点的值
    //     } else if (root->val == y) {
    //         depth2 = depth;
    //         pre2 = pre;
    //     }
    //     dfs(root->left, depth + 1, root, x, y);
    //     dfs(root->right, depth + 1, root, x, y);
    // }
    // bool isCousins(TreeNode *root, int x, int y) {
    //     dfs(root, 0, nullptr, x, y);
    //     return depth1 == depth2 && pre1 != pre2;
    // }
};