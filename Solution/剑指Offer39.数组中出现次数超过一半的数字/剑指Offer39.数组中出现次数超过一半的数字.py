'''
Descroption: 剑指 Offer 39. 数组中出现次数超过一半的数字
Author: EmoryHuang
Date: 2021-07-03 15:21:26
解题思路:
方法一：排序后取中位数
由于数字的出现次数超过一半，因此中位数一定是这个数
方法二：哈希表
'''


class Solution:
    # 方法一：排序后取中位数
    def majorityElement(self, nums: List[int]) -> int:
        return sorted(nums)[len(nums)//2]

    # 方法二：哈希表
    # def majorityElement(self, nums: List[int]) -> int:
    #     return max( collections.Counter(nums).items() ,key= lambda x : x[1] )[0]
