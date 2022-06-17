'''
Descroption: LeetCode 730. ͳ�Ʋ�ͬ����������
Author: EmoryHuang
Date: 2022-06-10 09:33:43
Method:
�� dp[i][j] ��ʾ�ַ����� i �� j �Ļ������и���
�� s[i] == s[j] == x, ��ô���� s[i+1, j-1] �е�����һ�����Ĵ�����������ͷβ���� x ����µĻ��Ĵ�
    �� s[i+1, j-1] ��û���ַ��� x ��ȣ������ xx �� x����ʱ���� 2 + dp[i+1][j-1] * 2 �����Ĵ�
    �� s[i+1, j-1] ����һ���ַ��� x ��ȣ������ xx����ʱ���� 1 + dp[i+1][j-1] * 2 �����Ĵ�
    �� s[i+1, j-1] �������������ϵ��ַ��� x ��ȣ�����Ҫɾ���ظ�����Ĳ��֣���ʱ���� dp[i+1][j-1] * 2 - dp[left + 1][right - 1] �����Ĵ�
        ���� left �� right ��ʾ s[i+1, j-1] ���� x ��ȵ��ַ�����ʼ����ֹλ��
�� s[i] != s[j], �� dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1]
'''


class Solution:
    def countPalindromicSubsequences(self, s: str) -> int:
        MOD = 10**9 + 7
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        # ��ʼ�������ַ�
        for i in range(n):
            dp[i][i] = 1

        for length in range(2, n + 1):
            for j in range(length - 1, n):
                i = j - length + 1
                if s[i] == s[j]:
                    # ���� s[i+1, j-1] ���� s[i] ��ȵ��ַ���λ��
                    low, high = i + 1, j - 1
                    while low <= high and s[low] != s[i]:
                        low += 1
                    while low <= high and s[high] != s[i]:
                        high -= 1
                    if low > high:
                        # s[i+1, j-1] ��û���ַ��� x ���
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % MOD
                    elif low == high:
                        # s[i+1, j-1] ����һ���ַ��� x ���
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % MOD
                    else:
                        # s[i+1, j-1] �������������ϵ��ַ��� x ���
                        dp[i][j] = (dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1]) % MOD
                else:
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) % MOD
        return dp[0][n - 1]
