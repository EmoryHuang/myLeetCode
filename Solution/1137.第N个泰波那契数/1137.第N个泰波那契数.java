/*
 * @Descroption: LeetCode 1137. 第 N 个泰波那契数
 * @Author: EmoryHuang
 * @Date: 2023-07-21 10:07:50
 * @Method:
 * 动态规划
 */

import java.util.*;

class Solution {
    public int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;
        int a = 0, b = 1, c = 1;
        for (int i = 3; i <= n; i++) {
            int temp = a;
            a = b;
            b = c;
            c = temp + a + b;
        }
        return c;
    }
}