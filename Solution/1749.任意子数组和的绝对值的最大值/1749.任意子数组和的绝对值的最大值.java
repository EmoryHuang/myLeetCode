/*
 * @Description: LeetCode 1749. 任意子数组和的绝对值的最大值
 * @Author: EmoryHuang
 * @Date: 2023-08-08 09:20:20
 * @Method:
 * 动态规划
 * 分别对最大值和最小值进行讨论
 */

import java.util.*;

class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int positiveMax = 0, negativeMin = 0;
        int positiveSum = 0, negativeSum = 0;
        for (int num : nums) {
            positiveSum += num;
            positiveMax = Math.max(positiveMax, positiveSum);
            positiveSum = Math.max(0, positiveSum);

            negativeSum += num;
            negativeMin = Math.min(negativeMin, negativeSum);
            negativeSum = Math.min(0, negativeSum);
        }
        return Math.max(positiveMax, -negativeMin);
    }
}