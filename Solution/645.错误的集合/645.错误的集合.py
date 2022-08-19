'''
Descroption: LeetCode 645. 错误的集合
Author: EmoryHuang
Date: 2021-07-04 12:51:42
解题思路:
方法一：数学
方法二：哈希表
'''


class Solution:
    # 数学
    def findErrorNums(self, nums: List[int]) -> List[int]:
        s = sum(set(nums))
        return [sum(nums) - s, len(nums) * (len(nums) + 1) // 2 - s]

    # 哈希表
    # def findErrorNums(self, nums: List[int]) -> List[int]:
    #     hash = [0] * len(nums)
    #     for num in nums:
    #         hash[num - 1] += 1
    #     return [hash.index(2) + 1, hash.index(0) + 1]
