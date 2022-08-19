'''
Descroption: LeetCode 639. 解码方法 II
Author: EmoryHuang
Date: 2021-09-27 19:23:54
Method:
动态规划
dp[i]表示前i个字符的解码方案数
dp[i] = α * dp[i-1] + β * dp[i-2]
分别考虑一位数和两位数的解码方案
解码单个字符，分成 0、1~9、* 来分别讨论
解码两个字符，分成 **、*X、X*、XX 来分别讨论
'''


class Solution:
    def numDecodings(self, s: str) -> int:
        def decode1(c: str):
            # 解码单个字符
            if c == '0':
                return 0
            elif c == '*':
                return 9  # [1 - 9]
            return 1

        def decode2(c1: str, c2: str):
            if c1 == c2 == '*':
                return 15  # [11 - 19] and [21 - 26] 共 15 种可能
            if c1 == '*':
                if c2 <= '6':
                    return 2  # c1 == 1 或 c1 == 2
                return 1  # c1 == 1
            if c2 == '*':
                if c1 == '1':
                    return 9  # c2 == 1 - 9
                elif c1 == '2':
                    return 6  # c2 == 1 - 6
                return 0
            sum = int(c1) * 10 + int(c2)
            if 10 <= sum <= 26:
                return 1
            return 0

        # dp[i]表示前i个字符的解码方案数
        # a = f[i-2], b = f[i-1], c = f[i]
        a, b, c = 0, 1, 0
        for i in range(1, len(s) + 1):
            # 考虑一位数的解码方案
            c = decode1(s[i - 1]) * b
            if i > 1:
                # 考虑两位数的解码方案
                c += decode2(s[i - 2], s[i - 1]) * a
            c %= 10**9 + 7
            a, b = b, c
        return c
