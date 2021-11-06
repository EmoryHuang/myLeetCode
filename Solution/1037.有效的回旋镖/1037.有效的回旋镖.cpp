/*
 * @Descroption: LeetCode 1037. 有效的回旋镖
 * @Author: EmoryHuang
 * @Date: 2021-11-06 15:54:08
 * @Method:
 * 简单题，计算三角形面积，判断是否为 0
 * S = abs(x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2))/2;
 */

class Solution {
   public:
    bool isBoomerang(vector<vector<int>>& points) {
        auto x = points[0], y = points[1], z = points[2];
        return (x[0] * (y[1] - z[1]) + y[0] * (z[1] - x[1]) + z[0] * (x[1] - y[1])) / 2.0 != 0;
    }
};