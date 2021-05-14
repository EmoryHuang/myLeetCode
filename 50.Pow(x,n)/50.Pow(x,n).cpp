/*
 * @Descroption: LeetCode 50. Pow(x, n)
 * @Author: EmoryHuang
 * @Date: 2021-03-22 17:19:36
 * @解题思路: 快速幂算法，
 * 详细算法可以看 [快速幂算法详解](https://emoryhuang.github.io/blog/1504958816.html)
 */

class Solution {
   public:
    double myPow(double x, long n) {
        double ans = 1;
        if (n == 0 || x == 1) return 1;
        if (n < 0) return 1 / myPow(x, -n);  // 若 n < 0
        while (n > 0) {
            if (n & 1) ans = ans * x;
            x = x * x;
            n >>= 1;
        }
        return ans;
    }
};