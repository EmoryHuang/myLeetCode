'''
Descroption: LeetCode 120. ��������С·����
Author: EmoryHuang
Date: 2021-07-29 14:48:42
Method:
��̬�滮
dp[i][j] ��ʾ��i��j�е���С·����
״̬ת�Ʒ��̣�dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
'''


class Solution:
    # ���䶯̬�滮
    # def minimumTotal(self, triangle: List[List[int]]) -> int:
    #     n = len(triangle)
    #     if n == 1:
    #         return triangle[0][0]
    #     # dp[i][j] ��ʾ��i��j�е���С·����
    #     dp = [[0] * n for _ in range(n)]
    #     for i, num in enumerate(triangle[-1]):
    #         dp[n - 1][i] = num
    #     for i in range(n - 2, -1, -1):
    #         for j in range(i + 1):
    #             dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
    #     return dp[0][0]

    # ԭ���޸�
    # def minimumTotal(self, triangle: List[List[int]]) -> int:
    #     n = len(triangle)
    #     for i in range(n - 1, 0, -1):
    #         for j in range(i):
    #             triangle[i - 1][j] += min(triangle[i][j], triangle[i][j + 1])
    #     return triangle[0][0]

    # һά�ռ�
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        n = len(triangle)
        if n == 1:
            return triangle[0][0]
        dp = triangle[-1]
        for i in range(n - 2, -1, -1):
            for j in range(i + 1):
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
        return dp[0]