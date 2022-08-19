'''
Descroption: LeetCode 1414. 和为 K 的最少斐波那契数字数目
Author: EmoryHuang
Date: 2021-06-05 15:25:00
解题思路:
贪心思想，从大到小选择斐波那契数字
'''


class Solution:
    def findMinFibonacciNumbers(self, k: int) -> int:
        a, b, count = 1, 1, 0
        f = [a, b]
        while a + b <= k:
            f.append(a + b)
            a, b = b, a + b
        for num in f[::-1]:
            if k >= num:
                k -= num
                count += 1
        return count
