/*
 * @Description: LeetCode 200. 岛屿数量
 * @Author: EmoryHuang
 * @Date: 2023-08-11 14:37:30
 * @解题思路:
 * 方法一：并查集
 * 方法二：dfs
 */

import java.util.*;

class Solution {
    int[] parent;

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y) {
        parent[find(x)] = find(y);
    }

    public int numIslands(char[][] grid) {
        int[][] dirs = {{1, 0}, {0, 1}};
        int m = grid.length, n = grid[0].length;
        parent = new int[m * n];
        for (int i = 0; i < m * n; i++) {
            parent[i] = i;
        }
        int ans = 0, ocean = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '0') {
                    ocean++;
                } else {
                    for (int[] dir : dirs) {
                        int x = i + dir[0], y = j + dir[1];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
                            merge(i * n + j, x * n + y);
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m * n; i++) {
            if (parent[i] == i) ans++;
        }
        return ans - ocean;
    }
}