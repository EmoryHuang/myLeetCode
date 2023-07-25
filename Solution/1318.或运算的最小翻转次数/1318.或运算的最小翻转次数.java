/*
 * @Descroption: LeetCode 1318. 或运算的最小翻转次数
 * @Author: EmoryHuang
 * @Date: 2023-07-21 11:22:20
 * @Method:
 * 位运算
 */

import java.util.*;

class Solution {
    public int minFlips(int a, int b, int c) {
        int ans = 0;
        for (int i = 0; i < 31; ++i) {
            int bit_a = (a >> i) & 1;
            int bit_b = (b >> i) & 1;
            int bit_c = (c >> i) & 1;
            if (bit_c == 0) {
                ans += bit_a + bit_b;
            } else {
                ans += (bit_a + bit_b == 0) ? 1 : 0;
            }
        }
        return ans;
    }
}