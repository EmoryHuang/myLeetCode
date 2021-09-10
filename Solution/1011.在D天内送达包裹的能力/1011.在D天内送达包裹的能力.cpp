/*
 * @Descroption: LeetCode 1011. �� D �����ʹ����������
 * @Author: EmoryHuang
 * @Date: 2021-04-26 13:20:36
 * @����˼·:
 * ʹ�ö��ֲ��ң���߽�Ϊ���� `weights` ��Ԫ�ص����ֵ���ұ߽�Ϊ���� `weights` ��Ԫ�صĺ�
 * �������İ�����������ͬһ��������͡�����������������������������xʱ������Ҫ�����һ�������ó������������µ�һ�죬���������±�����
 * ����������������󣬾͵õ���������Ҫ���͵���������󽫡�������Ҫ���͵��������� D ���бȽ�
 */

class Solution {
   public:
    int shipWithinDays(vector<int>& weights, int D) {
        int right = 0, left = 0;
        for (int w : weights) {
            right += w;           // rightΪweights��Ԫ��֮��
            left = max(left, w);  // leftΪweights�е����ֵ
        }
        while (left < right) {
            int tmp = 0, day = 1;                 // tmpΪÿ���˻���
            int mid = left + (right - left) / 2;  // midΪ�˻�����
            for (int w : weights) {
                tmp += w;
                if (tmp > mid) {
                    day++;  // ��һ������
                    tmp = w;
                }
            }
            if (day <= D)  // ����D��
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};