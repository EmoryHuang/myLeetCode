/*
 * @Descroption: LeetCode 2300. 咒语和药水的成功对数
 * @Author: EmoryHuang
 * @Date: 2023-07-20 10:38:55
 * @Method:
 * 二分查找
 */

import java.util.*;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int n = spells.length;
        int[] ans = new int[n];
        Arrays.sort(potions);
        for (int i = 0; i < n; i++) {
            ans[i] = getSuccess(spells[i], potions, success);
        }
        return ans;
    }

    int getSuccess(int spell, int[] potions, long success) {
        int left = 0, right = potions.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((long) spell * potions[mid] >= success) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return potions.length - left;
    }
}