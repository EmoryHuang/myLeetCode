/*
 * @Descroption: LeetCode 1926. �Թ������������ĳ���
 * @Author: EmoryHuang
 * @Date: 2021-08-16 20:20:33
 * @Method:
 * ����������������߽���Ҳ�����ڣ���˵���ҵ��˳���
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
                // �������߽���Ҳ������
                if ((x == 0 || x == m - 1 || y == 0 || y == n - 1) && ans) return ans;
                // ����4������
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && maze[nx][ny] == '.') {
                        // ���Ϊ����
                        maze[nx][ny] = '+';
                        q.push({nx, ny});
                    }
                }
            }
        }
        return -1;
    }
};