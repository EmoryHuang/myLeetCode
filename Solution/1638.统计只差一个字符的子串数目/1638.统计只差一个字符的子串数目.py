'''
Descroption: LeetCode 1638. 统计只差一个字符的子串数目
Author: EmoryHuang
Date: 2023-03-27 09:35:30
Method:
枚举所有子串并判断是否只差一个字符
'''


class Solution:
    def countSubstrings(self, s: str, t: str) -> int:
        ans = 0
        m, n = len(s), len(t)
        for i in range(m):
            for j in range(n):
                k, diff = 0, 0
                while i + k < m and j + k < n:
                    if s[i + k] != t[j + k]:
                        diff += 1
                    if diff == 1:
                        ans += 1
                    elif diff > 1:
                        break
                    k += 1
        return ans