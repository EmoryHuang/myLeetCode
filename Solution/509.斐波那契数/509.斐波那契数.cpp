/*
 * @Descroption: LeetCode 509. 斐波那契数
 * @Author: EmoryHuang
 * @Date: 2021-04-26 15:52:36
 * @解题思路: 简单题，斐波那契数列，给出了三种方法
 */

class Solution {
   public:
    // 方法一：递归
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }

    // 方法二：数组
    // int fib(int n) {
    //     if (n == 0 || n == 1) return n;
    //     vector<int> f(n + 1);
    //     f[0] = 0;
    //     f[1] = 1;
    //     for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    //     return f[n];
    // }

    // 方法三：替换
    // int fib(int n) {
    //     if (n == 0) return 0;
    //     int a = 0, b = 1;
    //     for (int i = 2; i <= n; i++) {
    //         b = a + b;
    //         a = b - a;
    //     }
    //     return b;
    // }
};