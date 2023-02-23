'''
Descroption: LeetCode 1806. 还原排列的最少操作步数
Author: EmoryHuang
Date: 2023-01-09 08:55:33
Method:
按题目要求直接模拟
'''


class Solution:
    def reinitializePermutation(self, n: int) -> int:
        perm = list(range(n))
        target = perm.copy()
        step = 0
        while True:
            step += 1
            perm = [
                perm[n // 2 + (i - 1) // 2] if i % 2 else perm[i // 2] for i in range(n)
            ]
            if perm == target:
                return step
