/*
 * @Descroption: LeetCode 435. 无重叠区间
 * @Author: EmoryHuang
 * @Date: 2021-06-14 14:12:00
 * @解题思路:
 * 方法一：贪心思想，
 * 以数对的第二个值从小到大排序
 * 然后比较 intervals[i][0] 和 pre 的大小
 *
 * 方法二：动态规划
 * dp[i]表示以 intervals[i] 结尾的最长链的长度
 * 状态转移方程：dp[i] = max(dp[i], dp[j] + 1)
 */

class Solution {
   public:
    // 方法一：贪心
    static bool cmp(vector<int> a, vector<int> b) { return a[1] < b[1]; }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 0, pre = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < pre) {
                ans++;
                continue;
            }
            pre = intervals[i][1];
        }
        return ans;
    }

    // 方法二：动态规划
    // static bool cmp(vector<int> a, vector<int> b) { return a[0] < b[0]; }
    // int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    //     sort(intervals.begin(), intervals.end(), cmp);
    //     int n = intervals.size();
    //     // dp[i]表示以 intervals[i] 结尾的最长链的长度
    //     vector<int> dp(n, 1);
    //     for (int i = 1; i < n; i++) {
    //         for (int j = 0; j < i; j++) {
    //             if (intervals[i][0] >= intervals[j][1]) dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //     }
    //     return n - *max_element(dp.begin(), dp.end());
    // }
};