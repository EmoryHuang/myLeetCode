/*
 * @Descroption: LeetCode 653. 两数之和 IV - 输入 BST
 * @Author: EmoryHuang
 * @Date: 2021-06-02 12:46:00
 * @解题思路:
 * 方法一：使用set
 * 使用set记录数组元素
 *
 * 方法二：中序遍历 + 双指针
 * 通过中序遍历的到顺序的数组，然后再寻找和为 k 的数
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
    // 方法一：使用set
    // bool find(TreeNode *root, int k, set<int> &st) {
    //     if (root == nullptr) return false;
    //     if (st.count(k - root->val)) return true;
    //     st.insert(root->val);
    //     return find(root->left, k, st) || find(root->right, k, st);
    // }
    // bool findTarget(TreeNode *root, int k) {
    //     set<int> st;
    //     return find(root, k, st);
    // }

    // 方法二：中序遍历 + 双指针
    void inorder(TreeNode *root, vector<int> &list) {
        if (root) {
            inorder(root->left, list);
            list.push_back(root->val);
            inorder(root->right, list);
        }
    }
    bool findTarget(TreeNode *root, int k) {
        vector<int> list;
        inorder(root, list);
        int l = 0, r = list.size() - 1;
        while (l < r) {
            if (list[l] + list[r] == k)
                return true;
            else if (list[l] + list[r] > k)
                r--;
            else
                l++;
        }
        return false;
    }
};