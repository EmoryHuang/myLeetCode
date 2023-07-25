/*
 * @Descroption: LeetCode 162. 寻找峰值
 * @Author: EmoryHuang
 * @Date: 2023-07-20 10:48:03
 * @Method:
 * 二分查找
 */

import java.util.*;

class Solution {
    public int findPeakElement(int[] nums) {
        int left = 0, right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}