/*
 * @Descroption: ��ָ Offer II 098. ·������Ŀ
 * @Author: EmoryHuang
 * @Date: 2021-08-04 16:50:05
 * @Method:
 * ��̬�滮
 * ״̬ת�Ʒ��̣�dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
 */

class Solution {
   public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++) dp[j] += dp[j - 1];
        return dp.back();
    }
};