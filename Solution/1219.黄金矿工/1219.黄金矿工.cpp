/*
 * @Descroption: LeetCode 1219. 黄金矿工
 * @Author: EmoryHuang
 * @Date: 2021-08-10 14:26:39
 * @Method:
 * 回溯
 * dfs暴力遍历所有可能
 */

class Solution {
   public:
    vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
    int ans = 0, m, n;
    vector<vector<int>> vis;
    void dfs(int x, int y, int cur, vector<vector<int>>& grid) {
        ans = max(ans, cur);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n && vis[nx][ny] == 0 && grid[nx][ny]) {
                vis[nx][ny] = 1;
                dfs(nx, ny, cur + grid[nx][ny], grid);
                vis[nx][ny] = 0;
            }
        }
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<int> tmp(n);
        vis.resize(m, tmp);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) {
                    vis[i][j] = 1;
                    dfs(i, j, grid[i][j], grid);
                    vis[i][j] = 0;
                }
        return ans;
    }
};