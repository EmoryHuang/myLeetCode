'''
Descroption: ��ָ Offer 47. ���������ֵ
Author: EmoryHuang
Date: 2021-08-09 14:15:26
Method:
��̬�滮
״̬ת�Ʒ���
dp[i][j] = grid[i][j] + max(dp[i - 1][j], dp[i][j - 1])
'''


class Solution:
    def maxValue(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        # dp = [[0] * (n + 1) for i in range(m + 1)]
        dp = [0] * (n + 1)
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                # dp[i][j] = grid[i - 1][j - 1] + max(dp[i - 1][j], dp[i][j - 1])
                dp[j] = grid[i - 1][j - 1] + max(dp[j], dp[j - 1])
        # return dp[m][n]
        return dp[n]
