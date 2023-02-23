/*
 * @Descroption: LeetCode 1779. 找到最近的有相同 X 或 Y 坐标的点
 * @Author: EmoryHuang
 * @Date: 2022-12-01 09:39:35
 * @Method:
 * 遍历坐标数组，在有效坐标中找到曼哈顿距离最小的位置
 */

class Solution {
    public int nearestValidPoint(int x, int y, int[][] points) {
        int ans = -1, min_d = 0xffffff;
        for (int i = 0; i < points.length; i++) {
            if (x == points[i][0] || y == points[i][1]) {
                int d = Math.abs(x - points[i][0]) + Math.abs(y - points[i][1]);
                if (d < min_d) {
                    ans = i;
                    min_d = d;
                }
            }
        }
        return ans;
    }
}