/*
 * @Descroption: LeetCode 1009. 十进制整数的反码
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:28:36
 * @解题思路:
 * 原码 + 反码 = 2^n-1，n 为原码二进制位数
 */

class Solution {
   public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int num = 1;
        while (num <= N) num <<= 1;
        return num - 1 - N;
    }
};