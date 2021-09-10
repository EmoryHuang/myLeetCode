'''
Descroption: 面试题 08.03. 魔术索引
Author: EmoryHuang
Date: 2021-07-28 19:02:28
Method:
简单题，遍历数组
'''


class Solution:
    def findMagicIndex(self, nums: List[int]) -> int:
        for i, num in enumerate(nums):
            if num == i:
                return num
        return -1
