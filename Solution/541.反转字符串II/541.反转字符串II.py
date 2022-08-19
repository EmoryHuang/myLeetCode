'''
Descroption: LeetCode 541. 反转字符串 II
Author: EmoryHuang
Date: 2021-08-20 15:28:12
Method:
模拟，按题意每个 2k 个字符反转前 k 个
'''


class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        t = list(s)
        for i in range(0, len(t), 2 * k):
            t[i:i + k] = reversed(t[i:i + k])
        return "".join(t)
