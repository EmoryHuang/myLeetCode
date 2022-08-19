/*
 * @Descroption: LeetCode 1267. 统计参与通信的服务器
 * @Author: EmoryHuang
 * @Date: 2021-07-15 20:26:20
 * @解题思路:
 * 遍历两遍
 * 第一遍统计每行每列服务器的数量
 * 第二遍根据每行每列服务器的数量判读是否为连通
 */

class Solution {
   public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> row(n), col(m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1 && (row[i] > 1 || col[j] > 1)) ans++;
        return ans;
    }
};