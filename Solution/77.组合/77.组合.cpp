/*
 * @Descroption: LeetCode 77. 组合
 * @Author: EmoryHuang
 * @Date: 2021-05-12 16:17:36
 * @解题思路: 回溯 + 剪枝
 * 从 `1` 开始，如果 `p.size() < k`，那么就将元素依次放入 p，
 * 如果 `p.size() == k` 那么就将 `p` 放入 `ans`
 */

class Solution {
   public:
    void dfs(vector<vector<int>>& ans, vector<int>& p, int n, int k, int st) {
        if (p.size() == k) {
            ans.push_back(p);
            return;
        }
        for (int i = st; i <= n; i++) {
            if (p.size() < k) {
                p.push_back(i);
                dfs(ans, p, n, k, i + 1);  // 递归
                p.pop_back();              // 撤销选择
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> p;
        dfs(ans, p, n, k, 1);
        return ans;
    }
};