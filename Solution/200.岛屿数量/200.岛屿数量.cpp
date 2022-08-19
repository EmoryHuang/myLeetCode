/*
 * @Descroption: LeetCode 200. 岛屿数量
 * @Author: EmoryHuang
 * @Date: 2021-08-19 10:07:52
 * @Method:
 * 方法一：并查集
 * i * col + j唯一标识每个元素，合并连通的元素为一个集合
 * 岛屿数量 = 连通块的个数 + 水的元素个数
 * 遍历每个元素的时候，统计水的个数
 * 方法二：BFS
 * 广度优先遍历，每访问一个点就将其置 0，统计连通数量
 * 方法三：DFS
 * 与 BFS 类似，每访问一个点就将其置 0
 */

class Solution {
   public:
    // 方法一：并查集
    // vector<int> parent;
    // int find(int x) {
    //     if (x != parent[x]) parent[x] = find(parent[x]);
    //     return parent[x];
    // }
    // void _union(int x, int y) { parent[find(x)] = find(y); }
    // int numIslands(vector<vector<char>>& grid) {
    //     vector<int> dx = {0, 1}, dy = {1, 0};
    //     int m = grid.size(), n = grid[0].size();
    //     // 初始化并查集
    //     for (int i = 0; i < m * n; i++) parent.push_back(i);
    //     int ans = 0, ocean = 0;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == '0')
    //                 ocean++;
    //             else {
    //                 // 只需向右和向下查看
    //                 for (int k = 0; k < 2; k++) {
    //                     int x = i + dx[k];
    //                     int y = j + dy[k];
    //                     if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == '1') {
    //                         _union(i * n + j, x * n + y);
    //                     }
    //                 }
    //             }
    //     for (int i = 0; i < parent.size(); i++)
    //         if (i == parent[i]) ans++;
    //     return ans - ocean;
    // }

    // 方法二：BFS
    // int m, n;
    // vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    // void bfs(vector<vector<char>>& grid, int i, int j) {
    //     queue<pair<int, int>> q;
    //     q.push({i, j});
    //     while (!q.empty()) {
    //         auto [x, y] = q.front();
    //         q.pop();
    //         for (int i = 0; i < 4; i++) {
    //             int nx = x + dx[i];
    //             int ny = y + dy[i];
    //             if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') {
    //                 grid[nx][ny] = '0';
    //                 q.push({nx, ny});
    //             }
    //         }
    //     }
    // }
    // int numIslands(vector<vector<char>>& grid) {
    //     m = grid.size(), n = grid[0].size();
    //     int ans = 0;
    //     for (int i = 0; i < m; i++)
    //         for (int j = 0; j < n; j++)
    //             if (grid[i][j] == '1') {
    //                 ans++;
    //                 bfs(grid, i, j);
    //             }
    //     return ans;
    // }

    // 方法三：DFS
    int m, n;
    vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    void dfs(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '0';
        for (int k = 0; k < 4; k++) {
            int nx = i + dx[k];
            int ny = j + dy[k];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1') dfs(grid, nx, ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size(), n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
        return ans;
    }
};