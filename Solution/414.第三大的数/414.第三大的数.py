'''
Descroption: LeetCode 414. 第三大的数
Author: EmoryHuang
Date: 2021-10-06 14:30:25
Method:
遍历一次获取最大值，次大值，第三大值
若遇到一个更大的值，则分别对值进行传递
'''


class Solution:
    def thirdMax(self, nums: List[int]) -> int:
        a, b, c = float('-inf'), float('-inf'), float('-inf')
        for num in nums:
            if num == a or num == b or num == c:
                continue
            if num > a:
                a, b, c = num, a, b
            elif num > b:
                b, c = num, b
            elif num > c:
                c = num
        if c != float('-inf'):
            return c
        return a