/*
 * @Descroption: LeetCode 2008. 出租车的最大盈利
 * @Author: EmoryHuang
 * @Date: 2021-10-08 20:38:49
 * @Method:
 * 方法一：动态规划
 * dp[i] 表示以 i 结尾的位置能得到的最大利润
 * 若不载客，则有 dp[i] = dp[i - 1]
 * 若载客，则选择当前位置能获得的最大利润 dp[i] = max(dp[i], dp[start] + profit)
 *
 * 方法二：动态规划 + 二分
 * 状态转移方程: dp[i] = max(dp[i - 1], dp[r] + end - start + tip)
 * 使用二分查找，寻找距离当前终点最近的起点位置
 */

class Solution {
   public:
    // 方法一：动态规划
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        // dp[i] 表示以 i 结尾的位置能得到的最大利润
        vector<long long> dp(n + 1);
        vector<vector<pair<int, int>>> hash(n + 1);
        for (auto r : rides) hash[r[1]].push_back({r[0], r[1] - r[0] + r[2]});
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];  // 不载客
            for (auto [start, w] : hash[i]) dp[i] = max(dp[i], dp[start] + w);
        }
        return dp[n];
    }
};