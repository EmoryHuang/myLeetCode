/*
 * @Descroption: 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面
 * @Author: EmoryHuang
 * @Date: 2023-07-25 09:37:30
 * @Method:
 * 快慢指针
 */

import java.util.*;

class Solution {
    public int[] exchange(int[] nums) {
        int fast = 0, slow = 0;
        while (fast < nums.length) {
            if (nums[fast] % 2 == 1) {
                swap(nums, fast, slow);
                slow++;
            }
            fast++;
        }
        return nums;
    }

    void swap(int[] nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
}