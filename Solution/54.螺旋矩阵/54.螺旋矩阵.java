/*
 * @Description: LeetCode 54. 螺旋矩阵
 * @Author: EmoryHuang
 * @Date: 2023-08-04 14:56:52
 * @Method:
 * 模拟
 */

import java.util.*;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if (matrix == null || matrix.length == 0) {
            return ans;
        }
        int m = matrix.length, n = matrix[0].length;
        int total = m * n;
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        boolean[][] vis = new boolean[m][n];
        int x = 0, y = 0;
        int direction = 0;
        for (int i = 0; i < total; i++) {
            ans.add(matrix[x][y]);
            vis[x][y] = true;
            int nx = x + dirs[direction][0];
            int ny = y + dirs[direction][1];
            if (nx < 0 || nx >= m || ny < 0 || ny >= n || vis[nx][ny]) {
                direction = (direction + 1) % 4;
            }
            x += dirs[direction][0];
            y += dirs[direction][1];
        }
        return ans;
    }
}