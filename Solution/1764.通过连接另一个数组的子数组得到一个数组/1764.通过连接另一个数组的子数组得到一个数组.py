'''
Descroption: LeetCode 1764. 通过连接另一个数组的子数组得到一个数组
Author: EmoryHuang
Date: 2022-12-17 09:41:25
Method:
贪心
在数组中寻找匹配的子数组
'''


class Solution:
    def canChoose(self, groups: List[List[int]], nums: List[int]) -> bool:
        k = 0
        for g in groups:
            while k + len(g) <= len(nums):
                if nums[k:k + len(g)] == g:
                    k += len(g)
                    break
                k += 1
            else:
                return False
        return True