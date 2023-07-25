/*
 * @Descroption: LeetCode 746. 使用最小花费爬楼梯
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:13:17
 * @Method:
 * 动态规划
 * 状态转移方程：dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
 */

import java.util.*;

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        int pre = 0, cur = 0;
        for (int i = 2; i <= n; i++) {
            int next = Math.min(cur + cost[i - 1], pre + cost[i - 2]);
            pre = cur;
            cur = next;
        }
        return cur;
    }
}