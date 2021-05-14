/*
 * @Descroption: LeetCode 476. 数字的补数
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:34:36
 * @解题思路: 原码 + 反码 = 2^n-1，n 为原码二进制位数
 */

class Solution {
   public:
    int findComplement(int N) {
        if (N == 0) return 1;
        long num = 1;  // int会超出范围
        while (num <= N) num <<= 1;
        return num - 1 - N;
    }
};