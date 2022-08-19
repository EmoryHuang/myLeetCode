/*
 * @Descroption: LeetCode 1261. 在受污染的二叉树中查找元素
 * @Author: EmoryHuang
 * @Date: 2021-09-10 15:11:55
 * @Method:
 * 简单题，dfs还原树，同时记录值
 * 查找target是否存在即可
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
class FindElements {
   public:
    unordered_set<int> st;
    void dfs(TreeNode* root, int val) {
        if (!root) return;
        root->val = val;
        st.insert(val);
        dfs(root->left, 2 * val + 1);
        dfs(root->right, 2 * val + 2);
    }
    FindElements(TreeNode* root) { dfs(root, 0); }

    bool find(int target) { return st.count(target); }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */