/*
 * @Descroption: ��ָ Offer II 091. ��ˢ����
 * @Author: EmoryHuang
 * @Date: 2022-06-25 09:01:14
 * @Method:
 * ��̬�滮
 * dp[i][j]��ʾǰi�����ӵ�j����ɫ����С����
 * ״̬ת�Ʒ��̣�
 * dp[i][j] = min(dp[i-1][q], dp[i-1][k]) + cost[k][j]
 */

class Solution {
   public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 0)
                    dp[i][j] = costs[i][j];
                else
                    dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
            }
        }
        return min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
    }
};