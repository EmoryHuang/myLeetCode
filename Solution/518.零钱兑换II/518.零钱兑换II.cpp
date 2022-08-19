/*
 * @Descroption: LeetCode 518. ��Ǯ�һ� II
 * @Author: EmoryHuang
 * @Date: 2021-05-30 17:53:00
 * @����˼·:
 * ��ȫ��������
 * dp[j]��ʾ�ܽ��Ϊ j ��Ӳ���������
 * ״̬ת�Ʒ���
 * dp[j] = dp[j] + dp[j - coin]
 */

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[j]��ʾ�ܽ��Ϊ j ��Ӳ���������
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};