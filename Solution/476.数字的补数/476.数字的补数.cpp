/*
 * @Descroption: LeetCode 476. ���ֵĲ���
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:34:36
 * @����˼·: ԭ�� + ���� = 2^n-1��n Ϊԭ�������λ��
 */

class Solution {
   public:
    int findComplement(int N) {
        if (N == 0) return 1;
        long num = 1;  // int�ᳬ����Χ
        while (num <= N) num <<= 1;
        return num - 1 - N;
    }
};