'''
Descroption: LeetCode 789. 逃脱阻碍者
Author: EmoryHuang
Date: 2021-08-22 19:43:50
Method:
将题目换个说法，也就是比较是否有阻碍者比人物先到达目的地
'''


class Solution:
    def escapeGhosts(self, ghosts: List[List[int]], target: List[int]) -> bool:
        d = abs(target[0]) + abs(target[1])
        for ghost in ghosts:
            if abs(ghost[0] - target[0]) + abs(ghost[1] - target[1]) <= d:
                return False
        return True
