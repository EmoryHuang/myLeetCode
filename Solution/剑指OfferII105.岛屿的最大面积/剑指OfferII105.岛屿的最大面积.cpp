/*
 * @Descroption: 剑指 Offer II 105. 岛屿的最大面积
 * @Author: EmoryHuang
 * @Date: 2021-08-19 16:21:12
 * @Method:
 * 方法一：并查集
 * 初始时将每个位置都视为根，若周围是陆地，则和合并并记录每个连通图的节点数量
 * 方法二：BFS
 * 广度优先遍历，每访问一个点就将其置 0，记录每个连通图的节点数量，取最大值
 * 方法三：DFS
 * 与 BFS 类似，每访问一个点就将其置 0，记录每个连通图的节点数量，取最大值
 */

class Solution {
   public:
    // 方法一：并查集
    vector<int> parent, num;
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void _union(int x, int y) {
        int r1 = find(x), r2 = find(y);
        if (r1 != r2) {
            parent[r2] = r1;
            // 更新数量
            num[r1] += num[r2];
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> dx = {0, 1}, dy = {1, 0};
        int m = grid.size(), n = grid[0].size();
        // 初始化并查集
        for (int i = 0; i < m * n; i++) parent.push_back(i);
        num.resize(m * n);  // 更新集合大小
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1) {
                    num[i * n + j] = 1;
                    // 只需向右和向下查看
                    for (int k = 0; k < 2; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                            num[x * n + y] = 1;
                            _union(i * n + j, x * n + y);
                        }
                    }
                }
        return *max_element(num.begin(), num.end());
    }

    // 方法二：BFS
    // int m, n, ans = 0;
    // vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    // void bfs(vector<vector<int>>& grid, int i, int j) {
    //     queue<pair<int, int>> q;
    //     q.push({i, j});
    //     grid[i][j] = 0;  // 标记为访问
    //     int cnt = 1;     // 记录当前岛大小
    //     while (!q.empty()) {
    //         auto [x, y] = q.front();
    //         q.pop();
    //         for (int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) {
    //                 grid[nx][ny] = 0;  // 标记为访问
    //                 q.push({nx, ny});
    //                 cnt++;
    //             }
    //         }
    //     }
    //     ans = max(ans, cnt);
    // }
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     m = grid.size(), n = grid[0].size();
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == 1) {
    //                 bfs(grid, i, j);
    //             }
    //     return ans;
    // }

    // 方法三：DFS
    // int m, n;
    // vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    // int dfs(vector<vector<int>>& grid, int i, int j) {
    //     grid[i][j] = 0;  // 标记为访问
    //     int cnt = 1;
    //     for (int k = 0; k < 4; k++) {
    //         int nx = i + dx[k];
    //         int ny = j + dy[k];
    //         if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1) cnt += dfs(grid, nx, ny);
    //     }
    //     return cnt;
    // }
    // int maxAreaOfIsland(vector<vector<int>>& grid) {
    //     m = grid.size(), n = grid[0].size();
    //     int ans = 0;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == 1) {
    //                 ans = max(ans, dfs(grid, i, j));
    //             }
    //     return ans;
    // }
};