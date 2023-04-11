'''
Descroption: LeetCode 1040. 移动石子直到连续 II
Author: EmoryHuang
Date: 2023-04-07 09:30:10
Method:

'''


class Solution:
    def numMovesStonesII(self, stones: List[int]) -> List[int]:
        n = len(stones)
        stones.sort()
        e1 = stones[-2] - stones[0] - n + 2
        e2 = stones[-1] - stones[1] - n + 2
        max_move = max(e1, e2)
        if e1 == 0 or e2 == 0:
            return [min(2, max_move), max_move]
        max_cnt = left = 0
        for right, x in enumerate(stones):
            while stones[left] <= x - n:
                left += 1
            max_cnt = max(max_cnt, right - left + 1)
        return [n - max_cnt, max_move]
