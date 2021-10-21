/*
 * @Descroption: ��ָ Offer II 072. ��ƽ����
 * @Author: EmoryHuang
 * @Date: 2021-10-21 19:19:03
 * @Method:
 * ���⣬���ַ���ƽ����
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