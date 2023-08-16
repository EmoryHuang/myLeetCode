/*
 * @Description: LeetCode 41. 缺失的第一个正数
 * @Author: EmoryHuang
 * @Date: 2023-08-04 14:46:40
 * @Method:
 * 原地哈希
 */

import java.util.*;

class Solution {
    public int firstMissingPositive(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums, i, nums[i] - 1);
            }
        }
        for (int i = 0; i < n; i++) {
            if (i != nums[i] - 1) {
                return i + 1;
            }
        }
        return n + 1;
    }

    void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}