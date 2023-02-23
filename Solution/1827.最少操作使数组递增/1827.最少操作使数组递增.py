'''
Descroption: LeetCode 1827. 最少操作使数组递增
Author: EmoryHuang
Date: 2022-12-12 09:27:20
Method:
贪心
遍历数组，按照要求进行数组递增
'''

class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        ans = 0
        for i in range(1, n):
            if nums[i - 1] >= nums[i]:
                ans += nums[i - 1] - nums[i] + 1
                nums[i] = nums[i - 1] + 1
        return ans