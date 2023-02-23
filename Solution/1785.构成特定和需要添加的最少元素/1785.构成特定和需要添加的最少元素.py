'''
Descroption: LeetCode 1785. 构成特定和需要添加的最少元素
Author: EmoryHuang
Date: 2022-12-17 09:45:07
Method:
简单题，向上取整
'''


class Solution:
    def minElements(self, nums: List[int], limit: int, goal: int) -> int:
        return math.ceil(abs(goal - sum(nums)) / limit)