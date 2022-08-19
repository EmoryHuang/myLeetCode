'''
Descroption: ������ 08.11. Ӳ��
Author: EmoryHuang
Date: 2021-07-18 14:47:43
����˼·:
��������
dp[j]��ʾ��Ϊ j �ķ�������
״̬ת�Ʒ��̣�dp[j] += dp[j - coins[i]]
'''


class Solution:
    def waysToChange(self, n: int) -> int:
        coins = [25, 10, 5, 1]
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(len(coins)):
            for j in range(coins[i], n + 1):
                dp[j] += dp[j - coins[i]]
        return dp[-1] % 1000000007
