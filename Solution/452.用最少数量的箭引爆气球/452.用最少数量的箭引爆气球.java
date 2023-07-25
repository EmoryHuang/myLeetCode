/*
 * @Descroption: LeetCode 452. 用最少数量的箭引爆气球
 * @Author: EmoryHuang
 * @Date: 2023-07-22 10:29:31
 * @Method:
 * 贪心，根据右端点从小到大排序
 */

import java.util.*;

class Solution {
    public int findMinArrowShots(int[][] points) {
        Arrays.sort(points, (o1, o2) -> o1[1] < o2[1] ? -1 : 1);
        int pre = points[0][1], ans = 1;
        for (int i = 1; i < points.length; i++) {
            if (pre < points[i][0]) {
                ans++;
                pre = points[i][1];
            }
        }
        return ans;
    }
}