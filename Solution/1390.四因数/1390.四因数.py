'''
Descroption: LeetCode 1390. ������
Author: EmoryHuang
Date: 2021-08-20 20:12:18
Method:
���������е�ÿ������
����ǰ������������Ϊ4�������������֮��
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