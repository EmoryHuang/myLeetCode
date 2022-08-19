/*
 * @Descroption: LeetCode 778. 水位上升的泳池中游泳
 * @Author: EmoryHuang
 * @Date: 2021-08-24 17:00:34
 * @Method:
 * 方法一：并查集
 * 维护每个高度对应的位置，然后考虑 t 时刻时方格的位置，并向四个方向遍历
 * 若未超出边界并且高度小于等于 t（t时刻高度为t），那么进行合并
 * 最后检查(0, 0) 与 (n-1, n-1) 是否在一个连通图中。
 *
 * 方法二：二分 + BFS/DFS
 * 二分法判断 mid 时刻能否到达(n-1, n-1)
 * 具体来说，从(0, 0)开始进行广度优先遍历，
 * 若未超出边界并且高度小于等于 t，则标记为访问
 */

class Solution {
   public:
    // 方法一：并查集
    vector<int> parent;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void merge(int x, int y) { parent[find(x)] = find(y); }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1) return 0;
        // 初始化并查集
        for (int i = 0; i < n * n; i++) parent.push_back(i);
        // 得到每个高度对应的位置
        vector<pair<int, int>> pos(n * n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) pos[grid[i][j]] = {i, j};
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        // 遍历时间 t
        for (int t = 0; t < n * n; t++) {
            // t 时刻（高度为 t 的位置）
            auto [i, j] = pos[t];
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                // 若未超出边界并且高度小于等于 t
                if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t) {
                    merge(i * n + j, x * n + y);
                }
            }
            if (find(0) == find(n * n - 1)) return t;
        }
        return -1;
    }

    // 方法二：二分 + BFS/DFS
    // bool check(vector<vector<int>>& grid, int t) {
    //     if (grid[0][0] > t) return false;
    //     vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    //     int n = grid.size();
    //     vector<vector<int>> vis(n, vector<int>(n));
    //     vis[0][0] = 1;
    //     queue<pair<int, int>> q;
    //     q.push({0, 0});
    //     while (!q.empty()) {
    //         auto [i, j] = q.front();
    //         q.pop();
    //         for (int k = 0; k < 4; k++) {
    //             int x = i + dx[k], y = j + dy[k];
    //             if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] <= t && vis[x][y] == 0) {
    //                 q.push({x, y});
    //                 vis[x][y] = 1;
    //             }
    //         }
    //     }
    //     return vis[n - 1][n - 1] == 1;
    // }
    // int swimInWater(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     if (n == 1) return 0;
    //     int l = 0, r = n * n - 1;
    //     while (l < r) {
    //         int mid = l + (r - l) / 2;
    //         // 二分法判断 mid 时刻能否到达(n-1, n-1)
    //         if (check(grid, mid))
    //             r = mid;
    //         else
    //             l = mid + 1;
    //     }
    //     return l;
    // }
};