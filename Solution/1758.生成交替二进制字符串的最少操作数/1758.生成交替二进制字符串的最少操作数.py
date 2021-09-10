'''
Descroption: LeetCode 1758. 生成交替二进制字符串的最少操作数
Author: EmoryHuang
Date: 2021-08-15 12:40:43
Method:
遍历字符串，判断当前字符串和 0101...01 以及 1010...10的差异
'''


class Solution:
    def minOperations(self, s: str) -> int:
        cnt1, cnt2 = 0, 0
        for i in range(len(s)):
            if s[i] == str(i % 2):
                # 判断当前字符串和 0101...01的差异
                cnt1 += 1
            else:
                # 判断当前字符串和 1010...10的差异
                cnt2 += 1
        return min(cnt1, cnt2)
