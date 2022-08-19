/*
 * @Descroption: LeetCode 1155. 掷骰子的N种方法
 * @Author: EmoryHuang
 * @Date: 2021-05-26 17:01:17
 * @解题思路:
 * 动态规划，分组背包问题
 * dp[i][j]表示前i个骰子得到总和为j的组合情况数目
 * 状态转移方程：dp[i][j] = dp[i][j] + dp[i - 1][j - k], k = 1 ... f
 * 枚举次序为骰子个数，总和，每次得分数
 *
 * 当然，与背包问题类似，也可以将二维空间优化为一位空间
 * dp[j]表示得到总和为j的组合情况数目
 *
 * 更多有关解决背包问题的方法可以参考：[背包九讲学习笔记](https://emoryhuang.github.io/blog/4096131275.html)
 */

class Solution {
   public:
    // int numRollsToTarget(int d, int f, int target) {
    //     // dp[i][j]表示前i个骰子得到总和为j的组合情况数目
    //     vector<vector<int>> dp(d + 1, vector<int>(target + 1));
    //     dp[0][0] = 1;
    //     for (int i = 1; i <= d; i++)
    //         for (int j = i; j <= target; j++)
    //             for (int k = 1; k <= f; k++)
    //                 if (j >= k)
    //                     dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % 1000000007;
    //     return dp[d][target];
    // }

    // 空间优化
    int numRollsToTarget(int d, int f, int target) {
        // dp[j]表示得到总和为j的组合情况数目
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 1; i <= d; i++)
            for (int j = target; j >= 0; j--) {
                dp[j] = 0;  // 初始化为0
                for (int k = 1; k <= f; k++)
                    if (j >= k) dp[j] = (dp[j] + dp[j - k]) % 1000000007;
            }
        return dp[target];
    }
};