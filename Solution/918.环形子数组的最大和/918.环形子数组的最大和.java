/*
 * @Descroption: LeetCode 918. 环形子数组的最大和
 * @Author: EmoryHuang
 * @Date: 2023-07-20 09:39:56
 * @Method:
 * 动态规划
 * 分别考虑取到头尾和不取到头尾的情况
 */

import java.util.*;

class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int n = nums.length;
        int preMax = nums[0], sumMax = nums[0];
        int preMin = nums[0], sumMin = nums[0];
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            preMax = Math.max(preMax + nums[i], nums[i]);
            sumMax = Math.max(sumMax, preMax);
            preMin = Math.min(preMin + nums[i], nums[i]);
            sumMin = Math.min(sumMin, preMin);
            sum += nums[i];
        }
        if (sumMax < 0) {
            return sumMax;
        } else {
            return Math.max(sumMax, sum - sumMin);
        }
    }
}