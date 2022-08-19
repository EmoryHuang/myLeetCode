'''
Descroption: 剑指 Offer II 084. 含有重复元素集合的全排列 
Author: EmoryHuang
Date: 2021-08-06 16:59:23
Method:
简单回溯
由于有重复元素，因此可以在没有重复元素的基础上，判断当前元素是否为重复元素即可
'''


class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        ans, path, vis = [], [], [False] * len(nums)

        def dfs():
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i, num in enumerate(nums):
                if not vis[i]:
                    if i > 0 and nums[i] == nums[i - 1] and vis[i - 1]:
                        continue
                    vis[i] = True
                    path.append(num)
                    dfs()
                    vis[i] = False
                    path.pop()

        nums.sort()
        dfs()
        return ans
