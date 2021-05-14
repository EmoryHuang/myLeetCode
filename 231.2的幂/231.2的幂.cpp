/*
 * @Descroption: LeetCode 231. 2 ����
 * @Author: EmoryHuang
 * @Date: 2021-03-21 15:32:36
 * @����˼·:
 * ˵�� 2 ���������뵽�Ŀ϶�����һֱ���� 2�����ж��Ƿ�Ϊ 1
 *
 * ������������λ����
 * ���������� 2 ���ݣ���ô������ 1 �Ľ���Ǻ�������λΪ 1������ԭ���������������ض�Ϊ 0.
 */

class Solution {
   public:
    // ����һ
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n % 2 == 0) n /= 2;
        return n == 1;
    }

    // ������
    // bool isPowerOfTwo(int n) { return n > 0 && (n & (n - 1)) == 0; }
};