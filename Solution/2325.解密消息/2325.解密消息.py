'''
Descroption: LeetCode 2325. 解密消息
Author: EmoryHuang
Date: 2023-02-01 08:52:50
Method:
模拟，根据key生产对应表
'''


class Solution:
    def decodeMessage(self, key: str, message: str) -> str:
        cur = "a"
        rules = dict()

        for c in key:
            if c != " " and c not in rules:
                rules[c] = cur
                cur = chr(ord(cur) + 1)

        ans = "".join(rules.get(c, " ") for c in message)
        return ans
