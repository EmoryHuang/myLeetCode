'''
Descroption: LeetCode 1979. 找出数组的最大公约数
Author: EmoryHuang
Date: 2021-08-23 13:49:40
Method:
欧几里得算法求最大公约数
'''


class Solution:
    def findGCD(self, nums: List[int]) -> int:
        def gcd(a: int, b: int) -> int:
            return gcd(b, a % b) if b else a

        return gcd(max(nums), min(nums))
