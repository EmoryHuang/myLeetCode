/*
 * @Descroption: LeetCode 994. ���õ�����
 * @Author: EmoryHuang
 * @Date: 2021-08-04 16:10:19
 * @Method:
 * ���Ƚ����и��õ����Ӽ������
 * bfs������������Ԫ�أ���Ϊ�������ӣ�����ӣ�ÿ����һ�㣬ʱ���һ
 * �����������������������ӣ��򷵻�-1
 */

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<int> dx = {0, -1, 0, 1}, dy = {1, 0, -1, 0};
        queue<vector<int>> q;
        int n = grid.size(), m = grid[0].size();
        int mins = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2) q.push({i, j});
        while (!q.empty()) {
            int len = q.size();
            bool rotten = false;
            for (int i = 0; i < len; i++) {
                auto bad = q.front();
                int x = bad[0], y = bad[1];
                q.pop();
                for (int j = 0; j < 4; j++) {
                    int new_x = x + dx[j];
                    int new_y = y + dy[j];
                    if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && grid[new_x][new_y] == 1) {
                        grid[new_x][new_y] = 2;
                        q.push({new_x, new_y});
                        rotten = true;
                    }
                }
            }
            if (rotten) mins++;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 1) return -1;
        return mins;
    }
};