/*
 * @Descroption: ��ָ Offer II 088. ��¥�ݵ����ٳɱ�
 * @Author: EmoryHuang
 * @Date: 2021-08-09 20:30:44
 * @Method:
 * ��̬�滮
 * dp[i] ��ʾ����i������Ϊֹ����С����
 * ״̬ת�Ʒ��̣�dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
 */

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i];
        return min(dp[n - 1], dp[n - 2]);
    }
};