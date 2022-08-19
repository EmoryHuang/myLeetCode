/*
 * @Descroption: LeetCode 29. 两数相除
 * @Author: EmoryHuang
 * @Date: 2021-07-31 13:53:44
 * @Method:
 * 二分
 * 对于 y / x ,其结果一定在[0,x]之中，那么便可以采用二分的方法
 * 对于乘法，采用倍增的思想
 */

class Solution {
   public:
    long mul(long a, long b) {
        long ans = 0;
        while (b > 0) {
            if (b & 1 == 1) ans += a;
            b >>= 1;
            a += a;
        }
        return ans;
    }
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == 1) return INT_MIN;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        long x = dividend, y = divisor;
        bool isneg = false;
        if ((x > 0 && y < 0) || (x < 0 && y > 0)) isneg = true;
        x = x < 0 ? -x : x;
        y = y < 0 ? -y : y;
        long l = 0, r = x;
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (mul(mid, y) <= x)
                l = mid;
            else
                r = mid - 1;
        }
        long ans = isneg ? -l : l;
        return (int)ans;
    }
};