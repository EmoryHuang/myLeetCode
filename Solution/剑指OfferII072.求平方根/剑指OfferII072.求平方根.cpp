/*
 * @Descroption: 剑指 Offer II 072. 求平方根
 * @Author: EmoryHuang
 * @Date: 2021-10-21 19:19:03
 * @Method:
 * 简单题，二分法求平方根
 */

class Solution {
   public:
    int mySqrt(int x) {
        if (x == 1) return 1;
        int l = 0, r = x / 2;
        while (l < r) {
            int mid = l + r + 1 >> 1;
            if (mid <= x / mid)
                l = mid;
            else
                r = mid - 1;
        }
        return l;
    }
};