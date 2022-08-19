/*
 * @Descroption: LeetCode 1344. ʱ��ָ��ļн�
 * @Author: EmoryHuang
 * @Date: 2021-07-25 14:11:33
 * @����˼·:
 * ����ʱ��ͷ����ߵĽǶȣ�ȡ��С���Ǹ�
 */

class Solution {
   public:
    double angleClock(int hour, int minutes) {
        // ʱ��һСʱ��30�ȣ�һ������ 30 / 60 = 0.5��
        double harg = hour * 30 + minutes * 0.5;
        // ����һ������ 360 / 60 = 6��
        double marg = minutes * 6;
        if (abs(harg - marg) < 180)
            return abs(harg - marg);
        else
            return 360 - abs(harg - marg);
    }
};