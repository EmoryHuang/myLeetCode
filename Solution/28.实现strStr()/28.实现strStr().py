'''
Descroption: LeetCode 28. 实现 strStr()
Author: EmoryHuang
Date: 2021-12-24 10:28:16
Method:
字符串哈希
求出模式串的哈希值后，求出文本串每个长度为模式串长度的子串的哈希值，分别与模式串的哈希值比较
'''

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

        B = 2
        n, m = len(haystack), len(needle)

        # 计算 needle 的 hash 值
        needle_hash = 0
        for i in range(m):
            needle_hash = needle_hash * B + ord(needle[i])

        # 计算 haystack 的 hash 值
        h, p = [0] * (n + 1), [0] * (n + 1)
        p[0] = 1
        for i in range(n):
            h[i + 1] = h[i] * B + ord(haystack[i])
            p[i + 1] = p[i] * B

        # 计算子串的 hash 值
        for i in range(1, n - m + 2):
            j = i + m - 1
            sub_hash = h[j] - h[i - 1] * p[j - i + 1]
            if sub_hash == needle_hash:
                if haystack[i - 1:j] == needle:
                    return i - 1
        return -1
