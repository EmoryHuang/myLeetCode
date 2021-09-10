'''
Descroption: LeetCode 796. 旋转字符串
Author: EmoryHuang
Date: 2021-06-26 14:17:00
解题思路:
简单题，在 s + s 中判断是否存在子串 goal
'''


class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in (s + s)
