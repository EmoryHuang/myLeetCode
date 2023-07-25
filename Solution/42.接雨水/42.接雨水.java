/*
 * @Descroption: LeetCode 42. 接雨水
 * @Author: EmoryHuang
 * @Date: 2023-05-12 15:11:40
 * @Method:
 * 双指针，从两侧向中间移动，每次只移动较短的柱子
 */

import java.util.*;

class Solution {
    public int trap(int[] height) {
        int i = 0, j = height.length - 1;
        int imax = 0, jmax = 0;
        int ans = 0;
        while (i <= j) {
            if (imax < jmax) {
                // 如果左边的最高的柱子 < 右边的最高的柱子
                // 那么移动左边的柱子
                ans += Math.max(0, imax - height[i]);
                imax = Math.max(imax, height[i]);
                i++;
            } else {
                ans += Math.max(0, jmax - height[j]);
                jmax = Math.max(jmax, height[j]);
                j--;
            }
        }
        return ans;
    }
}