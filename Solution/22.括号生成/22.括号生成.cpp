/*
 * @Descroption: LeetCode 22. 括号生成
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:16:17
 * @解题思路:
 * dfs + 剪枝
 * 若左右括号的数量大于 n 则返回
 * 若右括号的数量大于左括号的数量则返回
 */

class Solution {
   public:
    /**
     * @param {int} l 左括号的数量
     * @param {int} r 右括号的数量
     */
    void dfs(vector<string>& ans, string str, int l, int r, int n) {
        if (l > n || r > n || r > l) return;
        if (l == n && r == n) {
            ans.push_back(str);
            return;
        }
        dfs(ans, str + '(', l + 1, r, n);
        dfs(ans, str + ')', l, r + 1, n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(ans, "", 0, 0, n);
        return ans;
    }
};