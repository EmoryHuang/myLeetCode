'''
Descroption: LeetCode 1753. 移除石子的最大得分
Author: EmoryHuang
Date: 2022-12-21 09:58:40
Method:
贪心
假设a ≤ b ≤ c
若a + b ≤ c，那么可以将所有a和b与c匹配
若a + b > c，那么c总是和a和b中较大的那个匹配
'''


class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        s = a + b + c
        max_val = max(a, b, c)
        return s - max_val if s < max_val * 2 else s // 2
