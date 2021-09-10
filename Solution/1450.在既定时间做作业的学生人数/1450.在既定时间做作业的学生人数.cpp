/*
 * @Descroption: LeetCode 1450. 在既定时间做作业的学生人数
 * @Author: EmoryHuang
 * @Date: 2021-04-19 13:23:36
 * @解题思路:
 * 简单题，判断查询时间是否在区间内即可
 */

class Solution {
   public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int len = startTime.size();
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (startTime[i] <= queryTime && endTime[i] >= queryTime) {
                ans++;
            }
        }
        return ans;
    }
};