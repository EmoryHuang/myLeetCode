'''
Descroption: 剑指 Offer 58 - II. 左旋转字符串
Author: EmoryHuang
Date: 2021-07-07 19:42:11
解题思路:
简单题, 切片或遍历拼接
'''


class Solution:
    # 切片
    def reverseLeftWords(self, s: str, n: int) -> str:
        return s[n:] + s[:n]

    # 遍历拼接
    # def reverseLeftWords(self, s: str, n: int) -> str:
    #     ans = ''
    #     for i in range(n, n + len(s)):
    #         ans += s[i % len(s)]
    #     return ans
