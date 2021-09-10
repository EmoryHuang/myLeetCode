/*
 * @Descroption: LeetCode 337. ��ҽ��� III
 * @Author: EmoryHuang
 * @Date: 2021-07-11 14:22:48
 * @����˼·:
 * �����͵��ǰ�ڵ㣬��ô���Һ��ӾͲ���͵
 * ����ǲ�͵��ǰ�ڵ㣬��ô���Һ��ӿ�͵�ɲ�͵��ȡ���ֵ
 * ��ǰ�ڵ��״̬���� (͵�Ľ���͵�Ľ��)
 */

#include <algorithm>
#include <cmath>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

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
    vector<int> dfs(TreeNode* root) {
        if (!root) return {0, 0};  // (͵�Ľ���͵�Ľ��)
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        // 0 ��ʾ͵��1��ʾ��͵
        // ͵��ǰ�ڵ㣬��͵�ӽڵ�
        int val1 = root->val + left[1] + right[1];
        // ��͵��ǰ�ڵ㣬��͵/͵�ӽڵ�
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return {val1, val2};
    }
    int rob(TreeNode* root) {
        vector<int> ans = dfs(root);
        return max(ans[0], ans[1]);
    }
};