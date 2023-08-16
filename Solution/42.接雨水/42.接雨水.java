/*
 * @Description: LeetCode 42. 接雨水
 * @Author: EmoryHuang
 * @Date: 2023-08-04 10:31:51
 * @Method:
 * 双指针，从两侧向中间移动，每次只移动较短的柱子
 */

import java.util.*;

class Solution {
    public int trap(int[] height) {
        int l = 0, r = height.length - 1;
        int ans = 0;
        int lmax = 0, rmax = 0;
        while (l <= r) {
            if (lmax <= rmax) {
                ans += Math.max(0, lmax - height[l]);
                lmax = Math.max(lmax, height[l]);
                l++;
            } else {
                ans += Math.max(0, rmax - height[r]);
                rmax = Math.max(rmax, height[r]);
                r--;
            }
        }
        return ans;
    }
}