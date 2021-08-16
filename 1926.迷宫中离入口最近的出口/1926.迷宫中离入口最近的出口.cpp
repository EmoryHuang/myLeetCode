/*
 * @Descroption: LeetCode 1926. 迷宫中离入口最近的出口
 * @Author: EmoryHuang
 * @Date: 2021-08-16 20:20:33
 * @Method:
 * 层序遍历，如果到达边界点且不是入口，则说明找到了出口
 */

class Solution {
   public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        int m = maze.size(), n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int ans = -1;
        while (!q.empty()) {
            int len = q.size();
            ans++;
            for (int i = 0; i < len; i++) {
                auto [x, y] = q.front();
                q.pop();
                // 如果到达边界点且不是入口
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) && ans) return ans;
                // 遍历4个方向
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        // 标记为访问
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};