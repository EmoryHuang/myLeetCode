/*
 * @Descroption: LeetCode 172. �׳˺����
 * @Author: EmoryHuang
 * @Date: 2022-03-25 08:48:56
 * @Method:
 * �׳˺����ĸ���ȡ����չ��ʽ�� 10 �ĸ������� 10 = 2 * 5
 * ��˽��ȡ���ڡ�2 ���������͡�5 ���������еĽ�Сֵ
 * �� 5 �ĸ�����Ȼ���ᳬ�� 2 �ĸ���
 * ���ֻͳ�� 5 �ĸ�������
 */

class Solution {
   public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n) {
            n /= 5;
            count += n;
        }
        return count;
    }
};