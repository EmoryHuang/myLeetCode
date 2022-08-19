/*
 * @Descroption: LeetCode 326. 3的幂
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:34:17
 * @解题思路:
 * 方法一：循环
 *
 * 方法二：换底公式
 *
 * 方法三：投机取巧
 * 1162261467为int型范围内最大的3的幂
 * 因此只需判断 1162261467 % n == 0
 */

class Solution {
   public:
    // 方法一：循环
    // bool isPowerOfThree(int n) {
    //     if (n <= 0) return false;
    //     while (n % 3 == 0) n = n / 3;
    //     return n == 1;
    // }

    // 方法二：换底公式
    // bool isPowerOfThree(int n) {
    //     if (n <= 0) return false;
    //     double a = log10(n) / log10(3);
    //     return a == floor(a);  // 判断换底后的log3n是否为整数
    // }

    // 方法三：投机取巧
    bool isPowerOfThree(int n) {
        // 1162261467为int型范围内最大的3的幂
        return n > 0 && 1162261467 % n == 0;
    }
};