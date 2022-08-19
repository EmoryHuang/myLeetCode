/*
 * @Descroption: LeetCode 1637. 两点之间不包含任何点的最宽垂直面积
 * @Author: EmoryHuang
 * @Date: 2021-10-18 18:45:30
 * @Method:
 * 按 x 从小到大排序，寻找最大间隔
 */

class Solution {
   public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size() - 1; i++) {
            ans = max(ans, points[i + 1][0] - points[i][0]);
        }
        return ans;
    }
};