/*
 * @Description: 剑指 Offer 66. 构建乘积数组
 * @Author: EmoryHuang
 * @Date: 2023-08-02 10:43:22
 * @Method:
 * 分别建立左右乘积列表
 */

import java.util.*;

class Solution {
    public int[] constructArr(int[] a) {
        int n = a.length;
        if (n == 0) {
            return new int[]{};
        }
        int[] left = new int[n];
        int[] right = new int[n];
        int[] ans = new int[n];

        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] * a[i - 1];
        }
        right[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i + 1];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
}