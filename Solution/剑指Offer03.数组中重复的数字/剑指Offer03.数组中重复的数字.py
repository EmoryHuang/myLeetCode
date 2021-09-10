'''
Descroption: 剑指 Offer 03. 数组中重复的数字
Author: EmoryHuang
Date: 2021-06-28 16:22:00
解题思路:
简单题，哈希表计数
'''


class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        hash = set()
        for num in nums:
            if num in hash:
                return num
            else:
                hash.add(num)
