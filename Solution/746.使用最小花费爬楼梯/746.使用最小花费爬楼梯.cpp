/*
 * @Descroption: LeetCode 746. ʹ����С������¥��
 * @Author: EmoryHuang
 * @Date: 2021-06-03 16:28:00
 * @����˼·:
 * ��̬�滮
 * dp[i] ��ʾ�ﵽ�±� i ����С����
 * ���ڿ���ѡ���±� 0 �� 1 ��Ϊ��ʼ���ݣ������ dp[0] = dp[1] = 0
 * ״̬ת�Ʒ��̣�dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
 */

class Solution {
   public:
    // �ռ临�Ӷȣ�O(n)
    // int minCostClimbingStairs(vector<int>& cost) {
    //     int n = cost.size();
    //     vector<int> dp(n + 1);
    //     dp[0] = dp[1] = 0;
    //     for (int i = 2; i <= n; i++)
    //         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
    //     return dp[n];
    // }

    // �ռ临�Ӷȣ�O(1)
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int pre = 0, cur = 0;
        for (int i = 2; i <= n; i++) {
            int next = min(pre + cost[i - 2], cur + cost[i - 1]);
            pre = cur;
            cur = next;
        }
        return cur;
    }
};