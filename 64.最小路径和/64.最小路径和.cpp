/*
 * @Descroption: LeetCode 64. ��С·����
 * @Author: EmoryHuang
 * @Date: 2021-03-23 17:01:36
 * @����˼·:��̬�滮
 * ��i��j������ͨ����i-1��j���ͣ�i��j-1��������Եõ������ѡ��`dp[i - 1][j]` �� `dp[i][j - 1]`
 * �н�С��һ�����ټ��ϣ�i��j������
 */

class Solution {
   public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = grid[i][j];
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};