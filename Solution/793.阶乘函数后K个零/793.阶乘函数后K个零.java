/*
 * @Descroption: LeetCode 793. 阶乘函数后 K 个零
 * @Author: EmoryHuang
 * @Date: 2022-08-28 11:00:19
 * @Method:
 * 数学 + 二分
 * 通过记录5的数量判断阶乘末尾零的个数
 * 之后通过二分求解
 */

class Solution {
    long getCnt(long x) {
        long cnt = 0;
        while (x != 0) {
            x /= 5;
            cnt += x;
        }
        return cnt;
    }

    int help(int x) {
        long l = 0, r = 5 * x;
        while (l < r) {
            long mid = l + r >> 1;
            if (getCnt(mid) >= x)
                r = mid;
            else
                l = mid + 1;
        }
        return (int) l;
    }

    public int preimageSizeFZF(int k) {
        if (k <= 1)
            return 5;
        return help(k + 1) - help(k);
    }
}