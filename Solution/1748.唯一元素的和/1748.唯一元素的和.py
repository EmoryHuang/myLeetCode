'''
Descroption: LeetCode 1748. 唯一元素的和
Author: EmoryHuang
Date: 2022-02-06 10:55:35
Method:
简单题，由于数据量较少，可以直接用hash记录元素出现的次数
'''


class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        cnt = [0] * 101
        for num in nums:
            cnt[num] += 1
        ans = 0
        for i in range(101):
            if cnt[i] == 1:
                ans += i
        return ans
