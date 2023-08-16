/*
 * @Description: LeetCode 238. 除自身以外数组的乘积
 * @Author: EmoryHuang
 * @Date: 2023-08-04 14:29:40
 * @Method:
 * 动态规划，分别记录当前位置 i 左右两侧的乘积
 */

import java.util.*;

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int[] ans = new int[n];
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * nums[i - 1];
        }
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * nums[i + 1];
        }
        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
}