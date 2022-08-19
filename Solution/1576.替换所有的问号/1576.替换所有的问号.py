'''
Descroption: LeetCode 1576. 替换所有的问号
Author: EmoryHuang
Date: 2022-01-05 08:50:58
Method:
简单题，遇到问号时，考虑其前后两个字符
只要取任意不同的字符就可以
头尾加问号避免考虑边界情况
'''


class Solution:
    def modifyString(self, s: str) -> str:
        # 头尾加问号避免考虑边界情况
        s = list("?" + s + "?")
        for i in range(1, len(s) - 1):
            if s[i] == "?":
                for j in range(97, 123):
                    if chr(j) != s[i + 1] and chr(j) != s[i - 1]:
                        s[i] = chr(j)
                        break
        return "".join(s[1:-1])
