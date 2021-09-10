/*
 * @Descroption: LeetCode 70. ��¥��
 * @Author: EmoryHuang
 * @Date:  2021-03-20 16:00:36
 * @����˼·:
 * ����һ����̬�滮
 * ������ x ��̨�׵ķ������������� x - 1 ��̨�׵ķ������������� x - 2 ��̨�׵ķ������ĺ�
 * f[i] = f[i - 1] + f[i - 2]
 *
 * ��������ͨ�ʽ
 * ������쳲��������У���ͨ�ʽ���ɵó���
 */

class Solution {
   public:
    // ����һ����̬�滮
    int climbStairs(int n) {
        if (n <= 1) return n;
        vector<int> f(n + 1);
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i <= n; i++) f[i] = f[i - 1] + f[i - 2];
        return f[n];
    }

    // ��������ͨ�ʽ
    // int climbStairs(int n) {
    //     double sqrt5 = sqrt(5);
    //     double fibn = pow((1 + sqrt5) / 2, n + 1) - pow((1 - sqrt5) / 2, n + 1);
    //     return (int)round(fibn / sqrt5);
    // }
};