/*
 * @Descroption: ��ָ Offer 10- II. ������̨������
 * @Author: EmoryHuang
 * @Date: 2021-06-29 20:13:00
 * @����˼·:
 * ���⣬���չ�ʽ����쳲���������
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