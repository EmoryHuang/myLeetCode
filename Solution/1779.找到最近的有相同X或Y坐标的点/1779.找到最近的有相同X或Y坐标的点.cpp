/*
 * @Descroption: LeetCode 1779. 找到最近的有相同 X 或 Y 坐标的点
 * @Author: EmoryHuang
 * @Date: 2021-04-21 15:38:36
 * @解题思路:
 * 简单题，首先判断`x`和`y`，然后寻找曼哈顿距离最小的点
 */

class Solution {
   public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n = points.size();
        int min = INT_MAX, pos = -1;
        for (int i = 0; i < n; i++) {
            if (points[i][0] == x || points[i][1] == y) {
                int dis = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (min > dis) {
                    min = dis;
                    pos = i;
                }
            }
        }
        return pos;
    }
};