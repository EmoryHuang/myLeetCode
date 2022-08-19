/*
 * @Descroption: LeetCode 342. 4����
 * @Author: EmoryHuang
 * @Date: 2021-05-31 19:10:00
 * @����˼·:
 * ����һ��ѭ��
 *
 * ��������ȡģ
 * ͨ�� n ���� 3 �������Ƿ�Ϊ 1 ���ж� n �Ƿ��� 4 ����
 */

class Solution {
   public:
    // ����һ��ʹ��ѭ��
    // bool isPowerOfFour(int n) {
    //     if (n == 1) return true;
    //     if (n <= 0 || n % 2 == 1) return false;
    //     while (n % 4 == 0) n >>= 2;
    //     return n == 1;
    // }

    // ��������ȡģ
    bool isPowerOfFour(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 2 == 1) return false;
        return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
    }
};