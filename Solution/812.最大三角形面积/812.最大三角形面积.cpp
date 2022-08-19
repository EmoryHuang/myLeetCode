/*
 * @Descroption: LeetCode 812. 最大三角形面积
 * @Author: EmoryHuang
 * @Date: 2021-10-18 19:02:03
 * @Method:
 * 数学
 * 任意多边型面积公式：S = 1 / 2 * ∑ |x_i * y_i+1 - x_i+1 * y_i|
 * 即: S = 1 / 2 * |(x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)|
 */

class Solution {
   public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        for (int i = 0; i < points.size() - 2; i++)
            for (int j = i + 1; j < points.size() - 1; j++)
                for (int k = j + 1; k < points.size(); k++) {
                    double x1 = points[i][0];
                    double y1 = points[i][1];
                    double x2 = points[j][0];
                    double y2 = points[j][1];
                    double x3 = points[k][0];
                    double y3 = points[k][1];
                    ans = max(ans, abs((x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)));
                }
        return ans / 2;
    }
};