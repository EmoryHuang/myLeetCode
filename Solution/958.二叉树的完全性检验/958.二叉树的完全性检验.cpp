/*
 * @Descroption: LeetCode 958. ����������ȫ�Լ���
 * @Author: EmoryHuang
 * @Date: 2021-07-10 14:28:43
 * @����˼·:
 * �����������������������սڵ㣬�����ı����Ͳ�Ӧ���ҽڵ���
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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false; // flag ��ʶ�Ƿ������սڵ�
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) { // �����ǰ�ڵ�Ϊ��
                flag = true;
                continue;
            }
            if (flag) return false;
            q.push(node->left);
            q.push(node->right);
        }
        return true;
    }
};