/*
 * @Descroption: LeetCode 1232. 缀点成线
 * @Author: EmoryHuang
 * @Date: 2021-06-21 21:27:00
 * @解题思路:
 * 简单题，判断每两个点之间的斜率是否相等，
 * 注意将除法转换为乘法（斜率可能为无穷）
 */

class Solution {
   public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        int x0 = coordinates[0][0], y0 = coordinates[0][1];
        int x = coordinates[1][0] - x0;
        int y = coordinates[1][1] - y0;
        for (int i = 2; i < n; ++i) {
            int xi = coordinates[i][0] - x0;
            int yi = coordinates[i][1] - y0;
            if (x * yi - y * xi) return false;
        }
        return true;
    }
};
