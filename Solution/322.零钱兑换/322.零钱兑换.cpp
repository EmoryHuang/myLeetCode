/*
 * @Descroption: LeetCode 322. ��Ǯ�һ�
 * @Author: EmoryHuang
 * @Date: 2021-05-20 16:20:51
 * @����˼·:
 * ��̬�滮���⣬��������
 * dp[i] ��ʾ��ɽ��Ϊ i ������Ӳ�Ҹ���
 * ״̬ת�Ʒ��̣�dp[i] = min(dp[i], dp[i - coin] + 1)
 * ������Ҫ���ǡ��Ϊ amount����˳�ʼ��ʱ��dp[0]=0�⣬��������ʼ��ΪINT_MAX
 */

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 0x3f3f3f3f);  // ��ʼ��ΪINT_MAX
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {  // �������
            for (int j = 0; j < n; j++) {
                if (coins[j] <= i) 
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] != 0x3f3f3f3f ? dp[amount] : -1;
    }
};