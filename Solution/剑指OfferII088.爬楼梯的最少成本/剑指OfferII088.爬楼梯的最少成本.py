'''
Descroption: ��ָ Offer II 088. ��¥�ݵ����ٳɱ�
Author: EmoryHuang
Date: 2021-08-09 20:19:15
Method:
��̬�滮
dp[i] ��ʾ����i������Ϊֹ����С����
״̬ת�Ʒ��̣�dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
'''


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * n
        dp[0], dp[1] = cost[0], cost[1]
        for i in range(2, n):
            dp[i] = min(dp[i - 2], dp[i - 1]) + cost[i]
        return min(dp[-1], dp[-2])
