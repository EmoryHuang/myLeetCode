/*
 * @Descroption: LeetCode 1009. ʮ���������ķ���
 * @Author: EmoryHuang
 * @Date: 2021-04-26 14:28:36
 * @����˼·:
 * ԭ�� + ���� = 2^n-1��n Ϊԭ�������λ��
 */

class Solution {
   public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int num = 1;
        while (num <= N) num <<= 1;
        return num - 1 - N;
    }
};