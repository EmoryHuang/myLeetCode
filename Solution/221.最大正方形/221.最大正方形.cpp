/*
 * @Descroption: LeetCode 221. ���������
 * @Author: EmoryHuang
 * @Date: 2021-05-23 15:12:11
 * @����˼·:
 * ��̬�滮
 * �����λ�õ�ֵ�� 1���� dp(i,j) ��ֵ�����Ϸ����󷽺����Ϸ�����������λ�õ� dp ֵ����
 * dp[i][j] = 1 + min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]);
 */

class Solution {
   public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans * ans;
    }
};