/*
 * @Descroption: LeetCode 367. ��Ч����ȫƽ����
 * @Author: EmoryHuang
 * @Date: 2021-04-23 14:49:36
 * @����˼·: ƽ�����жϣ��ڲ�ʹ�� sqrt ������£�����ʹ�ö��ֲ��ң����߿���ʹ��ţ�ٵ�����
 */

class Solution {
   public:
    // ����һ�����ֲ���
    bool isPerfectSquare(int num) {
        if (num < 2) return true;
        long left = 2, right = num / 2;
        while (left <= right) {
            long x = left + (right - left) / 2;
            if (x * x == num)
                return true;
            else if (x * x > num)
                right = x - 1;
            else
                left = x + 1;
        }
        return false;
    }

    // ��������ţ�ٵ�����
    // bool isPerfectSquare(int num) {
    //     if (num < 2) return true;
    //     long x = num / 2;
    //     while (x * x > num) x = (x + num / x) / 2;
    //     return (x * x == num);
    // }
};