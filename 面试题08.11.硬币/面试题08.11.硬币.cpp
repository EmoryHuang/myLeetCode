/*
 * @Descroption: ������ 08.11. Ӳ��
 * @Author: EmoryHuang
 * @Date: 2021-07-18 14:50:05
 * @����˼·:
 * ��������
 * dp[j]��ʾ��Ϊ j �ķ�������
 * ״̬ת�Ʒ��̣�dp[j] += dp[j - coins[i]]
 */

class Solution {
   public:
    int waysToChange(int n) {
        vector<int> coins = {25, 10, 5, 1};
        vector<long> dp(n + 1);
        dp[0] = 1;
        for (int i = 0; i < 4; i++)
            for (int j = coins[i]; j <= n; j++) 
                dp[j] += dp[j - coins[i]];
        return dp[n] % 1000000007;
    }
};