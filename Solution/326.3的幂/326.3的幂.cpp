/*
 * @Descroption: LeetCode 326. 3����
 * @Author: EmoryHuang
 * @Date: 2021-05-28 15:34:17
 * @����˼·:
 * ����һ��ѭ��
 *
 * �����������׹�ʽ
 *
 * ��������Ͷ��ȡ��
 * 1162261467Ϊint�ͷ�Χ������3����
 * ���ֻ���ж� 1162261467 % n == 0
 */

class Solution {
   public:
    // ����һ��ѭ��
    // bool isPowerOfThree(int n) {
    //     if (n <= 0) return false;
    //     while (n % 3 == 0) n = n / 3;
    //     return n == 1;
    // }

    // �����������׹�ʽ
    // bool isPowerOfThree(int n) {
    //     if (n <= 0) return false;
    //     double a = log10(n) / log10(3);
    //     return a == floor(a);  // �жϻ��׺��log3n�Ƿ�Ϊ����
    // }

    // ��������Ͷ��ȡ��
    bool isPowerOfThree(int n) {
        // 1162261467Ϊint�ͷ�Χ������3����
        return n > 0 && 1162261467 % n == 0;
    }
};