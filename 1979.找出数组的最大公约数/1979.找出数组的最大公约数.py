'''
Descroption: LeetCode 1979. �ҳ���������Լ��
Author: EmoryHuang
Date: 2021-08-23 13:49:40
Method:
ŷ������㷨�����Լ��
'''


class Solution:
    def findGCD(self, nums: List[int]) -> int:
        def gcd(a: int, b: int) -> int:
            return gcd(b, a % b) if b else a

        return gcd(max(nums), min(nums))
