/*
 * @Descroption: LeetCode 693. 交替位二进制数
 * @Author: EmoryHuang
 * @Date: 2021-05-01 20:20:36
 * @解题思路:
 * 依次比较后两位数是否相等，若不相等则返回 `false`
 */

class Solution {
   public:
    bool hasAlternatingBits(int n) {
        while (n) {
            if ((n & 1) == ((n >> 1) & 1)) return false;
            n >>= 1;
        }
        return true;
    }
};