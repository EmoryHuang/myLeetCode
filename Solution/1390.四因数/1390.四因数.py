'''
Descroption: LeetCode 1390. 四因数
Author: EmoryHuang
Date: 2021-08-20 20:12:18
Method:
遍历数组中的每个数，
若当前数的因数个数为4个，则计数因数之和
'''


class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        def count_divisors(num: int) -> int:
            d = set()
            for i in range(1, ceil(sqrt(num)) + 1):
                if num % i == 0:
                    d.add(i)
                    d.add(num // i)
            if len(d) == 4:
                return sum(d)
            return 0

        ans = 0
        for num in nums:
            ans += count_divisors(num)
        return ans