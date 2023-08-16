/*
 * @Description: LeetCode 70. 爬楼梯
 * @Author: EmoryHuang
 * @Date: 2023-08-16 09:57:30
 * @解题思路:
 * 动态规划
 * dp[i] = dp[i - 1] + dp[i - 2]
 */

import java.util.*;

class Solution {
    public int climbStairs(int n) {
        if (n == 1 || n == 2) {
            return n;
        }
        int a = 1, b = 2;
        for (int i = 2; i < n; i++) {
            int c = b;
            b += a;
            a = c;
        }
        return b;
    }
}