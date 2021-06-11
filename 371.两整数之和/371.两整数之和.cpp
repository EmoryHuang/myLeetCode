/*
 * @Descroption: LeetCode 371. ������֮��
 * @Author: EmoryHuang
 * @Date: 2021-06-11 17:22:00
 * @����˼·:
 * ��������a, b
 * a ^ b���޽�λ�����
 * a & b�õ�ÿһλ�Ľ�λ
 * ���޽�λ��ӵĽ�����λ���ϵ���� ֱ����λΪ0
 */

class Solution {
   public:
    int getSum(int a, int b) {
        int sum = a ^ b;
        int carry = (unsigned int)(a & b) << 1;
        if (carry) return getSum(sum, carry);
        return sum;
    }
};