'''
Descroption: LeetCode 1365. 有多少小于当前数字的数字
Author: EmoryHuang
Date: 2021-06-22 19:49:00
解题思路:
cnt[i] 表示数字 i 出现的次数。
那么对于数字 i 而言，小于它的数目就为 cnt[0...i-1] 的总和
'''


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        cnt = [0] * 101
        for num in nums:
            cnt[num] += 1
        for i in range(1, 101):
            cnt[i] += cnt[i - 1]
        ans = []
        for i in range(len(nums)):
            if nums[i] == 0:
                ans.append(0)
            else:
                ans.append(cnt[nums[i] - 1])
        return ans
