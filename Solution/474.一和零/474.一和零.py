'''
Descroption: LeetCode 474. һ����
Author: EmoryHuang
Date: 2021-06-06 14:54:00
����˼·:
0-1 �������⣬�� m �� n �������
dp[i][j]��ʾ�� i �� 0 �� j �� 1 ʱ����Ӽ���С
״̬ת�Ʒ��̣�dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1)
'''


class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        # dp[i][j]��ʾ��i��0��j��1ʱ����Ӽ���С
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for s in strs:
            cnt0 = s.count('0')
            cnt1 = s.count('1')
            for i in range(m, cnt0 - 1, -1):
                for j in range(n, cnt1 - 1, -1):
                    dp[i][j] = max(dp[i][j], dp[i - cnt0][j - cnt1] + 1)
        return dp[m][n]
