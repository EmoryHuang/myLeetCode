'''
Descroption: LeetCode 849. 到最近的人的最大距离
Author: EmoryHuang
Date: 2021-06-13 15:07:00
解题思路:
寻找最长的连续0，在头尾部分特殊处理
'''


class Solution:
    def maxDistToClosest(self, seats: List[int]) -> int:
        start, ans = -1, 0
        for i in range(len(seats)):
            if seats[i] == 1:
                if start == -1:  # 第一个数
                    ans = i
                else:
                    ans = max(ans, int((i - start) / 2))
                start = i
        ans = max(len(seats) - start - 1, ans)  # 最后一个数
        return ans
