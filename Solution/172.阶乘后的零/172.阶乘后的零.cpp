/*
 * @Descroption: LeetCode 172. 阶乘后的零
 * @Author: EmoryHuang
 * @Date: 2022-03-25 08:48:56
 * @Method:
 * 阶乘后的零的个数取决于展开式中 10 的个数，而 10 = 2 * 5
 * 因此结果取决于「2 的数量」和「5 的数量」中的较小值
 * 而 5 的个数必然不会超过 2 的个数
 * 因此只统计 5 的个数即可
 */

class Solution {
   public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n) {
            n /= 5;
            count += n;
        }
        return count;
    }
};