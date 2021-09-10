'''
Descroption: LeetCode 1221. 分割平衡字符串
Author: EmoryHuang
Date: 2021-08-23 19:19:07
Method:
贪心，计数L和R的个数，若个数相等则记录并重置数量
'''


class Solution:
    def balancedStringSplit(self, s: str) -> int:
        l, r = 0, 0
        ans = 0
        for c in s:
            if c == 'L': l += 1
            if c == 'R': r += 1
            if l == r:
                ans += 1
                l, r = 0, 0
        return ans