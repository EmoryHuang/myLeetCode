'''
Descroption: LeetCode 375. �����ִ�С II
Author: EmoryHuang
Date: 2021-11-12 19:18:37
Method:
����һ: dfs
�ݹ�õ���ǰ������ѡ�����ֵ���������õĽ��

������: ��̬�滮
dp[i][j] ��ʾ������ [i, j] ��ѡ�����С�ɱ�
cur = max(dp[l][i - 1], dp[i + 1][r]) + i
'''


class Solution:
    # ����һ: dfs
    # def getMoneyAmount(self, n: int) -> int:
    #     def dfs(l: int, r: int):
    #         if l >= r:
    #             return 0
    #         if cache[l][r]:
    #             return cache[l][r]
    #         ans = float('inf')
    #         # ����ѡ�������
    #         for i in range(l, r + 1):
    #             cur = max(dfs(l, i - 1), dfs(i + 1, r)) + i
    #             ans = min(ans, cur)
    #         cache[l][r] = ans
    #         return ans

    #     cache = [[0] * 200 for _ in range(200)]
    #     return dfs(1, n)

    # ������: ��̬�滮
    def getMoneyAmount(self, n: int) -> int:
        # dp[i][j] ��ʾ������ [i, j] ��ѡ�����С�ɱ�
        dp = [[0] * (n + 5) for _ in range(n + 5)]
        # ����ѡ�����
        for len in range(2, n + 1):
            # ������˵�
            for l in range(1, n - len + 2):
                r = l + len - 1
                dp[l][r] = float('inf')
                for i in range(l, r + 1):
                    cur = max(dp[l][i - 1], dp[i + 1][r]) + i
                    dp[l][r] = min(dp[l][r], cur)
        return dp[1][n]
