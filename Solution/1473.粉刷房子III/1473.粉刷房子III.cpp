/*
 * @Descroption: LeetCode 1473. 粉刷房子 III
 * @Author: EmoryHuang
 * @Date: 2021-05-04 14:02:36
 * @解题思路: 三维动态规划
 * `dp[i][j][k]`表示前 `i` 个房子组成 `j` 个街区，第 `i-1` 个房子的颜色为 `k` 的最小花费
 * - 如果当前房子没上色
 *      如果第 i-1 个房子与第 i 个房子颜色不同，则会形成新的街区
 *      如果第 i-1 个房子与第 i 个房子颜色相同，则街区数量不变
 *      并且需要加上 cost 费用
 * - 如果当前房子有颜色
 *      如果第 i-1 个房子与第 i 个房子颜色不同，则会形成新的街区
 *      如果第 i-1 个房子与第 i 个房子颜色相同，则街区数量不变
 *      无需 cost 费用
 * 最后取 `min(dp[m-1][target][k]),k∈[1,n]`
 */

class Solution {
   public:
    int Inf = INT_MAX / 2;
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k]表示前i个房子组成j个街区，第i-1个房子的颜色为k的最小花费
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n + 1, Inf)));
        // 初始化
        if (houses[0] == 0) {                  // 如果第一个房子没上色
            for (int k = 1; k <= n; k++)       // 遍历所有颜色
                dp[0][1][k] = cost[0][k - 1];  // 初始化
        } else
            dp[0][1][houses[0]] = 0;   // 第一个房子已经上色，无需花费
        // 循环可简化，这样写比较好理解
        for (int i = 1; i < m; i++) {  // 从第二个房子开始
            if (houses[i] == 0) {      // 如果当前房子没上色
                for (int curColor = 1; curColor <= n; curColor++) {      // curColor∈[1,n]
                    for (int preColor = 1; preColor <= n; preColor++) {  // prvColor∈[1,n]
                        for (int j = 1; j <= target; j++) {
                            if (curColor == preColor)
                                dp[i][j][curColor] =
                                    min(dp[i - 1][j][preColor] + cost[i][curColor - 1],
                                        dp[i][j][curColor]);
                            else
                                dp[i][j][curColor] =
                                    min(dp[i - 1][j - 1][preColor] + cost[i][curColor - 1],
                                        dp[i][j][curColor]);
                        }
                    }
                }
            } else {  //如果当前房子有颜色
                int curColor = houses[i];
                for (int preColor = 1; preColor <= n; preColor++) {  // prvColor∈[1,n]
                    for (int j = 1; j <= target; j++) {
                        if (curColor == preColor)
                            dp[i][j][curColor] = min(dp[i][j][curColor], dp[i - 1][j][preColor]);
                        else
                            dp[i][j][curColor] =
                                min(dp[i][j][curColor], dp[i - 1][j - 1][preColor]);
                    }
                }
            }
        }
        int ans = Inf;
        for (int i = 1; i <= n; i++) {
            ans = min(ans, dp[m - 1][target][i]);
        }
        return ans == Inf ? -1 : ans;
    }
};