/*
 * @Descroption: LeetCode 463. ������ܳ�
 * @Author: EmoryHuang
 * @Date: 2021-06-14 14:48:00
 * @����˼·:
 * ����ÿ��½�ظ��ӣ������ĸ������Ƿ�Ϊ½��
 * ��Ϊ½������Ҫ -1
 */

class Solution {
   public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1) cnt++;
                    }
                    ans += 4 - cnt;
                }
            }
        }
        return ans;
    }
};