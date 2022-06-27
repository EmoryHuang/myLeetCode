/*
 * @Descroption: LeetCode 508. ���ִ�����������Ԫ�غ�
 * @Author: EmoryHuang
 * @Date: 2022-06-19 11:13:14
 * @Method:
 * ʹ��dfs��������Ԫ�غ�
 * ��ϣ��ͳ������Ԫ�غͳ��ִ���
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
    unordered_map<int, int> map;
    int maxCnt = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int sum = dfs(root->left) + dfs(root->right) + root->val;
        map[sum]++;
        maxCnt = max(maxCnt, map[sum]);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto& i : map) {
            if (i.second == maxCnt) res.push_back(i.first);
        }
        return res;
    }
};