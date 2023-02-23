'''
Descroption: LeetCode 1752. 检查数组是否经排序和轮转得到
Author: EmoryHuang
Date: 2022-11-27 10:36:10
Method:
遍历数组，检查非递增点的数目
'''

class Solution:
    def check(self, nums: List[int]) -> bool:
        cnt, idx, n = 0, 0, len(nums)
        while idx < n:
            if nums[idx] > nums[(idx + 1) % n]:
                cnt += 1
            idx += 1
        return cnt <= 1
