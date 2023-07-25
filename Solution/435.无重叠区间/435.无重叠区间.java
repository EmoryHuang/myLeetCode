/*
 * @Descroption: LeetCode 435. 无重叠区间
 * @Author: EmoryHuang
 * @Date: 2023-07-22 10:22:31
 * @Method:
 * 贪心，根据右端点从小到大排序
 */

import java.util.*;

class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        Arrays.sort(intervals, (o1, o2) -> o1[1] - o2[1]);
        int pre = intervals[0][1], ans = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (pre > intervals[i][0]) {
                ans++;
                continue;
            }
            pre = intervals[i][1];
        }
        return ans;
    }
}