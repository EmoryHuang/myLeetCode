/*
 * @Descroption: LeetCode 993. �����������ֵܽڵ�
 * @Author: EmoryHuang
 * @Date: 2021-05-17 14:43:26
 * @����˼·:
 * ����һ��BFS
 * ͨ����α����ķ����������У������еĽ��Ϊ pair��first �洢��ǰ��㣬second �洢���ڵ�
 * ���ڶ���������Ψһֵ����˵����� x ���� y ʱ���丸�ڵ���� parent
 * ÿ������һ�㣬�ж��Ƿ� parent[0] != parent[1]
 * ��ֻ������һ��ֵ�����������ͬһ��
 *
 * ��������DFS
 * ͨ��������ȱ�������������x����y,��¼x,y����Ⱥ͸��ڵ�
 * ����ж�����Ƿ���ȣ����ڵ��Ƿ�ͬ
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
    // ����һ��BFS
    bool isCousins(TreeNode *root, int x, int y) {
        // first �洢��ǰ��㣬second �洢���ڵ�
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({root, nullptr});
        while (!q.empty()) {
            int len = q.size();
            vector<TreeNode *> parent;  // ��¼���ڵ�
            for (int i = 0; i < len; i++) {
                auto node = q.front();
                TreeNode *cur = node.first;
                TreeNode *pre = node.second;
                q.pop();
                if (cur->val == x || cur->val == y) parent.push_back(pre);
                if (cur->left) q.push({cur->left, cur});
                if (cur->right) q.push({cur->right, cur});
            }
            if (parent.size() == 1)  // ֻ������һ��ֵ������ͬһ��
                return false;
            else if (parent.size() == 2)
                return parent[0] != parent[1];  // �жϸ��ڵ�
        }
        return false;
    }

    // ��������DFS
    // int depth1 = 0, depth2 = 0;  // �ֱ��¼������Ⱥ͸��ڵ��ֵ
    // TreeNode *pre1 = nullptr, *pre2 = nullptr;
    // void dfs(TreeNode *root, int depth, TreeNode *pre, int x, int y) {
    //     if (root == nullptr) return;
    //     if (root->val == x) {
    //         depth1 = depth;  // �������
    //         pre1 = pre;      // ���¸��ڵ��ֵ
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