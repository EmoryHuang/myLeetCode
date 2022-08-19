/*
 * @Descroption: LeetCode 495. ��Ī����
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:52:36
 * @����˼·:
 * ��Ŀ�ܼ򵥣������ص����⣬ֻ��Ҫ���������һ��ɨ��Ϳ��Լ�����ܵ��ж�����ʱ��
 */

class Solution {
   public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int len = timeSeries.size();
        if (len == 0) return 0;
        int ans = 0;
        for (int i = 0; i < len - 1; i++) {
            if (timeSeries[i] + duration <= timeSeries[i + 1])
                ans += duration;
            else
                ans += (timeSeries[i + 1] - timeSeries[i]);
        }
        return ans + duration;
    }
};