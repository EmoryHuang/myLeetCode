/*
 * @Descroption: 剑指 Offer 10- II. 青蛙跳台阶问题
 * @Author: EmoryHuang
 * @Date: 2021-06-29 20:13:00
 * @解题思路:
 * 简单题，按照公式计算斐波那契数列
 */

class Solution {
   public:
    int numWays(int n) {
        if (n == 0 || n == 1) return 1;
        int a = 0, b = 1;
        for (int i = 0; i < n; i++) {
            b = a + b;
            a = b - a;
            b %= 1000000007;
        }
        return b;
    }
};