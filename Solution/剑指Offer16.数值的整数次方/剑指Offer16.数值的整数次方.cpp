/*
 * @Descroption: 剑指 Offer 16. 数值的整数次方
 * @Author: EmoryHuang
 * @Date: 2021-06-27 15:25:00
 * @解题思路:
 * 快速幂算法
 */

class Solution {
   public:
    double myPow(double x, int n) {
        if (x == 1 || n == 0) return 1;
        double ans = 1;
        long b = n;
        if (n < 0) b = -b, x = 1 / x;
        while (b) {
            if (b & 1) ans *= x;
            x *= x;
            b >>= 1;
        }
        return ans;
    }
};