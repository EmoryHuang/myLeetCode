/*
 * @Description: LeetCode 980. 不同路径 III
 * @Author: EmoryHuang
 * @Date: 2023-08-04 09:30:48
 * @Method:
 * 回溯，从起始位置开始寻找所有路径
 */

import java.util.*;

class Solution {
    static int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    public int uniquePathsIII(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int startX = 0, startY = 0, cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                } else if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                    cnt++;
                }
            }
        }
        return dfs(grid, startX, startY, cnt);
    }

    private int dfs(int[][] grid, int x, int y, int cnt) {
        if (grid[x][y] == 2) {
            return cnt == 0 ? 1 : 0;
        }
        int m = grid.length, n = grid[0].length;
        int cur = grid[x][y];
        grid[x][y] = -1;
        int res = 0;
        for (int[] dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && (grid[nx][ny] == 0 || grid[nx][ny] == 2)) {
                res += dfs(grid, nx, ny, cnt - 1);
            }
        }
        grid[x][y] = cur;
        return res;
    }


}