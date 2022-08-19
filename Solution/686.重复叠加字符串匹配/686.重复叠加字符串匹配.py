'''
Descroption: LeetCode 686. 重复叠加字符串匹配
Author: EmoryHuang
Date: 2021-12-22 08:54:45
Method:
如果 A 的长度小于 B 的长度，这时 B 是 A 的重复子串，
则 A 的重复次数不超过 len(B) / len(A) + 2
'''


class Solution:
    def repeatedStringMatch(self, a: str, b: str) -> int:
        n = len(b) // len(a)
        rep = a
        # 如果 A 的长度小于 B 的长度，这时 B 是 A 的重复子串，
        # 则 A 的重复次数不超过 len(B) / len(A) + 2
        for i in range(1, n + 3):
            if b in rep:
                return i
            rep += a
        return -1