'''
Descroption: LeetCode 1848. ��Ŀ��Ԫ�ص���С����
Author: EmoryHuang
Date: 2021-06-17 15:17:00
����˼·:
���⣬����һ�����飬�ҵ� target ��Ȼ��Ѱ����С����
'''


class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        ans = 0x3f3f3f3f
        for i in range(len(nums)):
            if nums[i] == target:
                ans = min(ans, abs(i - start))
        return ans
