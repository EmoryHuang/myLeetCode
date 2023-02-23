/*
 * @Descroption: LeetCode 878. 第 N 个神奇数字
 * @Author: EmoryHuang
 * @Date: 2022-11-22 09:47:02
 * @Method:
 * 二分
 * 小于等于 x 中能被 a 整除的数的个数为 ⌊x/a⌋
 * 小于等于 x 中能被 b 整除的个数为 ⌊x/b⌋
 * 小于等于 x 中同时能被 a 和 b 整除的个数为 ⌊x/c⌋，其中 c 为 a 和 b 的最小公倍数
 * 因此小于等于 x 的「神奇数字」个数为 ⌊x/a⌋ + ⌊x/b⌋ - ⌊x/c⌋
 */

class Solution {
    int lcm(int a, int b) {
        return a * b / gcd(a, b);
    }

    int gcd(int a, int b) {
        return b != 0 ? gcd(b, a % b) : a;
    }

    public int nthMagicalNumber(int n, int a, int b) {
        long l = Math.min(a, b);
        long r = (long) n * Math.min(a, b);
        int c = lcm(a, b);
        while (l < r) {
            long mid = l + r >> 1;
            long cnt = mid / a + mid / b - mid / c;
            if (cnt >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return (int) (r % 1000000007);
    }
}