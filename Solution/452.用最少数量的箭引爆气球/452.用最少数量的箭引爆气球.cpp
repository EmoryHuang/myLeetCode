/*
 * @Descroption: LeetCode 452. 用最少数量的箭引爆气球
 * @Author: EmoryHuang
 * @Date: 2021-08-12 20:01:27
 * @Method:
 * 贪心
 * 按照右端点排序，
 * 将左端点与之前引爆的值作比较，找到当前箭能引爆的最大数量
 */

class Solution {
   public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> a, vector<int> b) { return a[1] < b[1]; });
        int pre = points[0][1];
        int ans = 1;
        for (auto point : points) {
            if (point[0] > pre) {
                ans++;
                pre = point[1];
            }
        }
        return ans;
    }
};