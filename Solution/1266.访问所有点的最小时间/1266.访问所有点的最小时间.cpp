/*
 * @Descroption: LeetCode 1266. 访问所有点的最小时间
 * @Author: EmoryHuang
 * @Date: 2021-10-09 20:02:35
 * @Method:
 * 数学，取 x 和 y 距离的最大值
 */

class Solution {
   public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int ans = 0;
        for (int i = 1; i < points.size(); i++) {
            int x1 = points[i - 1][0], y1 = points[i - 1][1];
            int x2 = points[i][0], y2 = points[i][1];
            ans += max(abs(x1 - x2), abs(y1 - y2));
        }
        return ans;
    }
};