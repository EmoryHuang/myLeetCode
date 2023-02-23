'''
Descroption: LeetCode 2293. 极大极小游戏
Author: EmoryHuang
Date: 2023-01-15 08:39:09
Method:
递归，长度等于1时返回，否则递归求解
'''

class Solution:
    def minMaxGame(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        ans = [0] * (n // 2)
        for i in range(n // 2):
            if i % 2:
                ans[i] = max(nums[2 * i], nums[2 * i + 1])
            else:
                ans[i] = min(nums[2 * i], nums[2 * i + 1])
        return self.minMaxGame(ans)
