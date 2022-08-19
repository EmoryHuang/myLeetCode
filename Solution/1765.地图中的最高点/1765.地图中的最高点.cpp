/*
 * @Descroption: LeetCode 1765. 地图中的最高点
 * @Author: EmoryHuang
 * @Date: 2021-08-27 16:38:25
 * @Method:
 * 找到所有的水域，放入队列
 * 然后进行广度优先遍历，向4个方向寻找陆地，修改高度 + 1
 */

class Solution {
   public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        queue<pair<int, int>> q;
        // 找到所有的水域，放入队列
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (isWater[i][j] == 1) q.push({i, j});
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        vector<vector<int>> ans(m, vector<int>(n));
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x >= 0 && x < m && y >= 0 && y < n && isWater[x][y] == 0) {
                    ans[x][y] = ans[i][j] + 1;
                    isWater[x][y] = 1;
                    q.push({x, y});
                }
            }
        }
        return ans;
    }
};