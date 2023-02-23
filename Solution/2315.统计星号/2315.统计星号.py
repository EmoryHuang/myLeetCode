'''
Descroption: LeetCode 2315. 统计星号
Author: EmoryHuang
Date: 2023-01-29 08:51:09
Method:
简单题，遍历字符串，获取不在竖线对之间的星号数量
'''


class Solution:
    def countAsterisks(self, s: str) -> int:
        ans = 0
        flag = False
        for c in s:
            if c == '|':
                flag = ~flag
            if not flag and c == '*':
                ans += 1
        return ans
