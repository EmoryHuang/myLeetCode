'''
Descroption: LeetCode 910. 最小差值 II
Author: EmoryHuang
Date: 2021-09-23 18:47:15
Method:
贪心 + 排序
排序后再次遍历，找到可能的新的最大值和最小值
'''


class Solution:
    def smallestRangeII(self, nums: List[int], k: int) -> int:
        nums.sort()
        ans = nums[-1] - nums[0]
        for i in range(len(nums) - 1):
            a, b = nums[i], nums[i + 1]
            cur = max(nums[-1] - k, a + k) - min(nums[0] + k, b - k)
            ans = min(ans, cur)
        return ans
