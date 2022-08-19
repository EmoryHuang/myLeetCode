/*
 * @Descroption: LeetCode 495. 提莫攻击
 * @Author: EmoryHuang
 * @Date: 2021-04-24 14:52:36
 * @解题思路:
 * 题目很简单，就是重叠问题，只需要对数组进行一次扫描就可以计算出总的中毒持续时间
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