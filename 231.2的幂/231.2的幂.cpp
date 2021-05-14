/*
 * @Descroption: LeetCode 231. 2 的幂
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:32:36
 * @解题思路:
 * 说到 2 的幂首先想到的肯定就是一直除以 2，再判断是否为 1
 *
 * 方法二：利用位运算
 * 如果这个数是 2 的幂，那么该数减 1 的结果是后面所有位为 1，再与原数进行与运算结果必定为 0.
 */

class Solution {
   public:
    // 方法一
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }

    // 方法二
    // bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};