'''
Descroption: LeetCode 1893. 检查是否区域内所有整数都被覆盖
Author: EmoryHuang
Date: 2021-07-20 20:13:09
解题思路:
遍历闭区间内的每一个整数，记录位于区间内的元素的数量
'''


class Solution:
    def isCovered(self, ranges: List[List[int]], left: int, right: int) -> bool:
        cnt = 0
        for i in range(left, right + 1):
            for l, r in ranges:
                if l <= i <= r:
                    cnt += 1
                    break
        return cnt == right - left + 1
