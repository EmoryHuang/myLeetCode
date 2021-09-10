/*
 * @Descroption: LeetCode 190. 颠倒二进制位
 * @Author: EmoryHuang
 * @Date: 2021-03-29 19:30:36
 * @解题思路:
 * 将 n 视作一个长为 32 的二进制串，从低位往高位枚举 n 的每一位，将其倒序添加到翻转结果 ans 中
 */

class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for (int i = 0; i < 32; i++) {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }
        return ans;
    }
};