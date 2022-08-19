/*
 * @Descroption: LeetCode 69. x ��ƽ����
 * @Author: EmoryHuang
 * @Date: 2021-03-27 10:49:36
 * @����˼·: ���Բ���ţ�ٵ������Ͷ���������
 * ��Ҫ˵һ�¶��ֲ��ң�x ƽ�������������� ans ������ k^2 �� x ����� k ֵ��
 * ��˿��Զ� k ���ж��ֲ��ң��Ӷ��õ��𰸣�
 * �ڶ��ֲ��ҵ�ÿһ���У�����ֻ��Ҫ�Ƚ��м�Ԫ��mid��ƽ����x�Ĵ�С��ϵ����ͨ���ȽϵĽ���������½�ķ�Χ
 * �����йض��ֲ��ҵ�̽�����Կ���[���ֲ���ѧϰ�ʼ�](https://emoryhuang.github.io/blog/158595231.html)
 */

class Solution {
   public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        while (left < right) {
            long long mid = left + (right - left + 1) / 2;
            if (mid <= x / mid)  //������ֹ���
                left = mid;
            else
                right = mid - 1;
        }
        return left;
    }
};