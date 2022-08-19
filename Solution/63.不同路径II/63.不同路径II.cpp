/*
 * @Descroption: LeetCode 63. ��ͬ·�� II
 * @Author: EmoryHuang
 * @Date: 2021-05-21 15:50:00
 * @����˼·:
 * ��̬�滮���⣬��[62.��ͬ·��]�Ļ�����������ϰ�������˼·��ͬ
 * ע���ϰ�������(0,0),(n-1,n-1)
 */

class Solution {
   public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = 0; i < n && obstacleGrid[i][0] == 0; i++) dp[i][0] = 1;
        for (int j = 0; j < m && obstacleGrid[0][j] == 0; j++) dp[0][j] = 1;
        for (int i = 1; i < n; i++)
            for (int j = 1; j < m; j++)
                if (obstacleGrid[i][j] == 0) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[n - 1][m - 1];
    }
};