'''
Descroption: LeetCode 2016. ����Ԫ��֮�������ֵ
Author: EmoryHuang
Date: 2021-10-15 20:40:55
Method:
���⣬���������ͬʱ�������Ԫ��
'''


class Solution:
    def maximumDifference(self, nums: List[int]) -> int:
        ans = -1
        left = nums[0]
        for i in range(1, len(nums)):
            if nums[i] > left:
                ans = max(ans, nums[i] - left)
            left = min(nums[i], left)
        return ans