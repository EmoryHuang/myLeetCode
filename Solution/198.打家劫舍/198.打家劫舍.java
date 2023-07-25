/*
 * @Descroption: LeetCode 198. 打家劫舍
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:17:55
 * @Method:
 * 动态规划
 * 状态转移方程：dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])
 */

import java.util.*;

class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        if (n == 1) return nums[0];
        int first = nums[0], second = Math.max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int next = Math.max(second, first + nums[i]);
            first = second;
            second = next;
        }
        return second;
    }
}