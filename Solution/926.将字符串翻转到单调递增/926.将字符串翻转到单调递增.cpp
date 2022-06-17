/*
 * @Descroption: LeetCode 926. 将字符串翻转到单调递增
 * @Author: EmoryHuang
 * @Date: 2022-06-11 09:25:47
 * @Method:
 * 动态规划
 * dp[i][0] 表示第 i 个字符为 0 时 s[0,i] 需要的最小反转次数
 * dp[i][1] 表示第 i 个字符为 1 时 s[0,i] 需要的最小反转次数
 * 状态转移方程
 * dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + s[i] == '0' ? 1 : 0
 * dp[i][0] = dp[i-1][0] + s[i] == '1' ? 1 : 0
 */

class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        int dp0 = 0, dp1 = 0;
        for (auto c : s) {
            dp1 = min(dp0, dp1) + (c == '0' ? 1 : 0);
            dp0 = dp0 + (c == '1' ? 1 : 0);
        }
        return min(dp0, dp1);
    }
};