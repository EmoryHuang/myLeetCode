/*
 * @Descroption: LeetCode 509. 쳲�������
 * @Author: EmoryHuang
 * @Date: 2021-04-26 15:52:36
 * @����˼·: ���⣬쳲��������У����������ַ���
 */

class Solution {
   public:
    // ����һ���ݹ�
    int fib(int n) {
        if (n == 0 || n == 1) return n;
        return fib(n - 1) + fib(n - 2);
    }

    // ������������
    // int fib(int n) {
    //     if (n == 0 || n == 1) return n;
    //     vector<int> f(n + 1);
    //     f[0] = 0;
    //     f[1] = 1;
    //     for (int i = 2; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
    //     return f[n];
    // }

    // ���������滻
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