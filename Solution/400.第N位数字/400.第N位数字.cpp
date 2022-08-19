/*
 * @Descroption: LeetCode 400. �� N λ����
 * @Author: EmoryHuang
 * @Date: 2021-11-30 09:13:03
 * @Method:
 * ģ��
 * ����Ϊ l �������� [10^(l - 1), 10^l - 1)] ���� 9 * 10^(l - 1) ��
 * �����жϵ� n λ�������ֵĳ��ȣ�Ȼ������� n λ�������ֵ�ֵ
 * �� n �������� 10^(l - 1) + (n_l - 1) / l
 * λ��Ϊ (n - 1) % l
 * */

class Solution {
   public:
    int findNthDigit(int n) {
        if (n <= 9) return n;
        long long l = 1, base = 9;
        while (n > base * l) {
            n -= base * l;
            l++;
            base *= 10;
        }
        int num = pow(10, l - 1) + (n - 1) / l;
        int pos = (n - 1) % l;
        return to_string(num)[pos] - '0';
    }
};