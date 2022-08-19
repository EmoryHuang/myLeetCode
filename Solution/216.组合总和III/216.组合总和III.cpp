/*
 * @Descroption: LeetCode 216. 组合总和 III
 * @Author: EmoryHuang
 * @Date: 2021-05-20 16:50:37
 * @解题思路:
 * dfs回溯
 * 「在 9 个数中选择 k 个数」的组合枚举，
 * 对于枚举到的所有组合，判断这个组合内元素之和是否为 n
 */

class Solution {
   public:
    vector<vector<int>> ans;
    vector<int> comb;
    void dfs(int k, int n, int cur) {
        if (n == 0 && comb.size() == k) ans.push_back(comb);
        if (n <= 0 || comb.size() > k) return;
        for (int i = cur; i <= 9; i++) {
            comb.push_back(i);
            dfs(k, n - i, i + 1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }
};