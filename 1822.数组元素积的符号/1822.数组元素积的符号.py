'''
Descroption: LeetCode 1822. 数组元素积的符号
Author: EmoryHuang
Date: 2021-06-17 15:38:00
解题思路:
简单题，数负数的数量，最后判断乘积结果
'''


class Solution:
    def arraySign(self, nums: List[int]) -> int:
        neg = 0
        for num in nums:
            if num == 0:
                return 0
            elif num < 0:
                neg += 1
        return 1 if neg % 2 == 0 else -1
