/*
 * @Description: LeetCode 11. 盛最多水的容器
 * @Author: EmoryHuang
 * @Date: 2023-08-04 10:09:55
 * @Method:
 * 双指针，从两边向中间移动，每次移动较小值
 */

import java.util.*;

class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int left = 0, right = n - 1;
        int ans = 0;
        while (left < right) {
            int v = Math.min(height[left], height[right]) * (right - left);
            ans = Math.max(ans, v);
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
}