/*
 * @Descroption: LeetCode 70. 爬楼梯
 * @Author: EmoryHuang
 * @Date:  2021-03-20 16:00:36
 * @解题思路:
 * 方法一：动态规划
 * 爬到第 x 级台阶的方案数是爬到第 x - 1 级台阶的方案数和爬到第 x - 2 级台阶的方案数的和
 * f[i] = f[i - 1] + f[i - 2]
 *
 * 方法二：通项公式
 * 发现是斐波那契数列，由通项公式即可得出答案
 */

class Solution {
   public:
    // 方法一：动态规划
    int climbStairs(int n) {
        if (n <= 1) return n;
        vector<int> f(n + 1);
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
        return f[n];
    }

    // 方法二：通项公式
    // int climbStairs(int n) {
    //     double sqrt5 = sqrt(5);
    //     double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    //     return (int)round(fibn / sqrt5);
    // }
};