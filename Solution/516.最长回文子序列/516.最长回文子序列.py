'''
Descroption: LeetCode 516. �����������
Author: EmoryHuang
Date: 2021-08-11 18:33:42
Method:
��̬�滮
dp[i][j]��ʾ��s[i]��s[j]�������������
״̬ת�Ʒ���
�� s[i] == s[j] ʱ��dp[i][j] = d[i+1][j-1] + 2
�� s[i] != s[j] ʱ��dp[i][j] = max(dp[i+1][j], dp[i][j-1])
'''


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        # dp[i][j]��ʾ��s[i]��s[j]�������������
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]