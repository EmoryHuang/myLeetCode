/*
 * @Descroption: LeetCode 1926. 迷宫中离入口最近的出口
 * @Author: EmoryHuang
 * @Date: 2023-07-19 09:38:37
 * @Method:
 * BFS
 * 到达边界则返回结果
 */

import java.util.*;

class Solution {
    public int nearestExit(char[][] maze, int[] entrance) {
        int[][] dirs = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
        int m = maze.length, n = maze[0].length;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(entrance);
        maze[entrance[0]][entrance[1]] = '+';
        int ans = -1;
        while (!queue.isEmpty()) {
            int len = queue.size();
            ans++;
            for (int i = 0; i < len; i++) {
                int[] cur = queue.poll();
                int x = cur[0], y = cur[1];
                // 到达边界
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) && ans != 0) {
                    return ans;
                }
                for (int j = 0; j < 4; j++) {
                    int nx = x + dirs[j][0], ny = y + dirs[j][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        maze[nx][ny] = '+';
                        queue.offer(new int[] { nx, ny });
                    }
                }
            }
        }
        return -1;
    }
}