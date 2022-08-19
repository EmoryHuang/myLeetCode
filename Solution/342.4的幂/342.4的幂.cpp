/*
 * @Descroption: LeetCode 342. 4的幂
 * @Author: EmoryHuang
 * @Date: 2021-05-31 19:10:00
 * @解题思路:
 * 方法一：循环
 *
 * 方法二：取模
 * 通过 n 除以 3 的余数是否为 1 来判断 n 是否是 4 的幂
 */

class Solution {
   public:
    // 方法一：使用循环
    // bool isPowerOfFour(int n) {
    //     if (n == 1) return true;
    //     if (n <= 0 || n % 2 == 1) return false;
    //     while (n % 4 == 0) n >>= 2;
    //     return n == 1;
    // }

    // 方法二：取模
    bool isPowerOfFour(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 2 == 1) return false;
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};