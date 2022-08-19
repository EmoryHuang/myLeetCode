/*
 * @Descroption: ��ָ Offer 32 - III. ���ϵ��´�ӡ������ III
 * @Author: EmoryHuang
 * @Date: 2021-07-03 14:09:39
 * @����˼·:
 * ���ղ�������ķ�����ӡ����
 * Ȼ����Ҫ��ת��ǰ��
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                auto node = q.front();
                q.pop();
                tmp.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            if (ans.size() % 2) reverse(tmp.begin(), tmp.end());
            ans.push_back(tmp);
        }
        return ans;
    }
};