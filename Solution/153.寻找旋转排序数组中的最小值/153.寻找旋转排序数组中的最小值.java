/*
 * @Description: LeetCode 153. 寻找旋转排序数组中的最小值
 * @Author: EmoryHuang
 * @Date: 2023-08-14 10:30:50
 * @解题思路:
 * 二分查找
 */

import java.util.*;

class Solution {
    public int findMin(int[] nums) {
        int l = 0, r = nums.length - 1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
}