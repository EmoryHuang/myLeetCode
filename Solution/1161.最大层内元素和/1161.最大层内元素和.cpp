/*
 * @Descroption: LeetCode 1161. ������Ԫ�غ�
 * @Author: EmoryHuang
 * @Date: 2021-05-26 17:17:17
 * @����˼·:
 * ���ò��������˼��
 * ά������ depth ����ǰ��ȣ�����ÿ���Ԫ��֮��
 * ���ز���Ԫ��֮�����Ĳ��
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
        int depth = 0, ans = 0;  // depth��¼���
        while (!q.empty()) {
            int n = q.size();
            depth++;
            int sum = 0;  // ��ǰ����Ԫ��֮��
            for (int i = 0; i < n; i++) {
                TreeNode *node = q.front();
                q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (sum > maxSum) {
                maxSum = sum;  // ����������Ԫ��֮��
                ans = depth;   // ���²��
            }
        }
        return ans;
    }
};