/*
 * @Descroption: LeetCode 363. 矩形区域不超过 K 的最大数值和
 * @Author: EmoryHuang
 * @Date: 2021-04-22 13:52:36
 * @解题思路: 与[304. 二维区域和检索 - 矩阵不可变]类似，
 * 利用动态规划求得二维矩阵区域和，而后遍历求得的矩阵，寻找不超过 K 的最大数值和
 */

class Solution {
   public:
    int dp[101][101];
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
        int ans = INT_MIN;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                for (int p = i; p <= m; p++)
                    for (int q = j; q <= n; q++) {
                        int tmp = dp[p][q] - dp[p][j - 1] - dp[i - 1][q] + dp[i - 1][j - 1];
                        if (tmp <= k) ans = max(ans, tmp);
                    }
        return ans;
    }
};