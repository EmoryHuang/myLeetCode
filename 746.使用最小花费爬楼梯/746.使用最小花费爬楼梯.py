'''
Descroption: LeetCode 746. ʹ����С������¥��
Author: EmoryHuang
Date: 2021-06-03 16:25:00
����˼·:
��̬�滮
dp[i] ��ʾ�ﵽ�±� i ����С����
���ڿ���ѡ���±� 0 �� 1 ��Ϊ��ʼ���ݣ������ dp[0] = dp[1] = 0
״̬ת�Ʒ��̣�dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
'''


class Solution:
    # �ռ临�Ӷȣ�O(n)
    # def minCostClimbingStairs(self, cost: List[int]) -> int:
    #     n = len(cost)
    #     dp = [0] * (n + 1)
    #     for i in range(2, n + 1):
    #         dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
    #     return dp[n]

    # �ռ临�Ӷȣ�O(1)
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        pre, cur = 0, 0
        for i in range(2, n + 1):
            next = min(cur + cost[i - 1], pre + cost[i - 2])
            pre, cur = cur, next
        return cur
