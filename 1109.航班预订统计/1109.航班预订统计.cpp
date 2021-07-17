/*
 * @Descroption: LeetCode 1109. 航班预订统计
 * @Author: EmoryHuang
 * @Date: 2021-07-17 14:57:17
 * @解题思路:
 * 差分思想，
 * 可以把题目理解为在 l 处上车 num 人，在 r 出下车 num 人
 * 每个座位的人数为前一个座位的人数加上当前人数变化
 */

class Solution {
   public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n);
        for (auto booking : bookings) {
            int l = booking[0], r = booking[1], num = booking[2];
            ans[l - 1] += num;
            if (r < n) ans[r] -= num;
        }
        for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
        return ans;
    }
};