/*
 * @Descroption: LeetCode 994. 腐烂的橘子
 * @Author: EmoryHuang
 * @Date: 2023-07-19 09:54:05
 * @Method:
 * BFS
 * 从每个腐烂的橘子开始
 */

import java.util.*;

class Solution {
    public int orangesRotting(int[][] grid) {
        int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        int m = grid.length, n = grid[0].length;
        int total = 0;
        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.offer(new int[] { i, j });
                }
                total += grid[i][j] == 0 ? 0 : 1;
            }
        }
        int ans = 0, cnt = 0;
        while (!queue.isEmpty()) {
            int len = queue.size();
            cnt += len;
            boolean flag = false;
            for (int i = 0; i < len; i++) {
                int[] cur = queue.poll();
                int x = cur[0], y = cur[1];
                for (int j = 0; j < 4; j++) {
                    int nx = x + dirs[j][0], ny = y + dirs[j][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        queue.offer(new int[] { nx, ny });
                        flag = true;
                    }
                }
            }
            ans += flag ? 1 : 0;
        }
        return total == cnt ? ans : -1;
    }
}