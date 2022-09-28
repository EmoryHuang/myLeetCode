/*
 * @Descroption: LeetCode 827. 最大人工岛
 * @Author: EmoryHuang
 * @Date: 2022-09-18 12:27:45
 * @Method:
 * 并查集
 * 使用并查集维护所有连通块大小，之后枚举所有可能翻转的位置寻找最优位置
 */

class Solution {
    int N = 501;
    int[] parents = new int[N * N];
    int[] sizes = new int[N * N];
    int[][] dirs = new int[][] { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

    int find(int x) {
        if (parents[x] != x)
            parents[x] = find(parents[x]);
        return parents[x];
    }

    void union(int a, int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb)
            return;
        if (sizes[pa] > sizes[pb])
            union(b, a);
        else {
            sizes[pb] += sizes[pa];
            parents[pa] = parents[pb];
        }
    }

    public int largestIsland(int[][] grid) {
        int n = grid.length;
        int ans = 0;
        // 初始化并查集
        for (int i = 1; i <= n * n; i++) {
            sizes[i] = 1;
            parents[i] = i;
        }
        // 遍历图并进行并查集合并，并记录每个连通块的大小
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                for (int[] d : dirs) {
                    int x = i + d[0], y = j + d[1];
                    if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0)
                        continue;
                    union(i * n + j + 1, x * n + y + 1);
                }
            }
        }
        // 再次遍历图，枚举并进行翻转
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = Math.max(ans, sizes[find(i * n + j + 1)]);
                } else {
                    int total = 1;
                    Set<Integer> set = new HashSet<>();
                    for (int[] d : dirs) {
                        int x = i + d[0], y = j + d[1];
                        if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0)
                            continue;
                        int root = find(x * n + y + 1);
                        if (set.contains(root))
                            continue;
                        total += sizes[root];
                        set.add(root);
                    }
                    ans = Math.max(ans, total);
                }
            }
        }
        return ans;
    }
}