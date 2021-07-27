'''
Descroption: LeetCode 516. �����������
Author: EmoryHuang
Date: 2021-07-27 20:07:53
Method:
��̬�滮
dp[i][j] ��ʾ s �ĵ� i ���ַ����� j ���ַ���ɵ��Ӵ��У���Ļ������г���
״̬ת�Ʒ��̣�
�� s[i] == s[j] �� dp[i][j] = dp[i + 1][j - 1] + 2
�� s[i] != s[j] �� dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
'''


class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            dp[i][i] = 1
            for j in range(i + 1, n):
                if s[i] == s[j]:
                    dp[i][j] = dp[i + 1][j - 1] + 2
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]
