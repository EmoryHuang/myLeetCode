'''
Descroption: LeetCode 1608. �������������ֵ
Author: EmoryHuang
Date: 2021-06-24 15:50:00
����˼·:
����Ȼ��Ѱ�� x������ǰһ����С�� x ��һ�������ڵ��� x
'''


class Solution:
    def specialArray(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        if nums[0] >= n:
            return len(nums)  # n �������ڵ��� n
        for i in range(1, n + 1):
            # i �������ڵ��� i
            if nums[n - i] >= i and nums[n - i - 1] < i:
                return i
        return - 1
