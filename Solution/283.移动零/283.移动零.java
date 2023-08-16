/*
 * @Description: LeetCode 283. 移动零
 * @Author: EmoryHuang
 * @Date: 2023-08-04 10:05:42
 * @Method:
 * 双指针，分别指向当前元素和非零元素末尾
 */

import java.util.*;

class Solution {
    public void moveZeroes(int[] nums) {
        int fast = 0, slow = 0;
        while (fast < nums.length) {
            if (nums[fast] != 0) {
                swap(nums, fast, slow);
                slow++;
            }
            fast++;
        }
    }

    void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}