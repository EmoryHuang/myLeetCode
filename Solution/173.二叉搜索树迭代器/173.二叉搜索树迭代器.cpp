/*
 * @Descroption: LeetCode 173. 二叉搜索树迭代器
 * @Author: EmoryHuang
 * @Date: 2021-03-28 20:30:36
 * @解题思路: 直接对二叉搜索树做一次完全的递归遍历，获取中序遍历的全部结果并保存在数组中
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
class BSTIterator {
   public:
    vector<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        while (root) {
            st.push_back(root);
            root = root->left;
        }
    }

    int next() {
        TreeNode* cur = st.back();
        st.pop_back();
        int val = cur->val;
        cur = cur->right;
        while (cur) {
            st.push_back(cur);
            cur = cur->left;
        }
        return val;
    }

    bool hasNext() { return !st.empty(); }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */