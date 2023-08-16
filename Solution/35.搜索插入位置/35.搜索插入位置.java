/*
 * @Description: LeetCode 35. 搜索插入位置
 * @Author: EmoryHuang
 * @Date: 2023-08-14 10:23:56
 * @解题思路:
 * 二分查找
 */

import java.util.*;

class Solution {
    public int searchInsert(int[] nums, int target) {
        int l = 0, r = nums.length;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
}