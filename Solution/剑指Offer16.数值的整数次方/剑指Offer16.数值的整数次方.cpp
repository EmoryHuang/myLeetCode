/*
 * @Descroption: ��ָ Offer 16. ��ֵ�������η�
 * @Author: EmoryHuang
 * @Date: 2021-06-27 15:25:00
 * @����˼·:
 * �������㷨
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