'''
Descroption: 剑指 Offer II 083. 没有重复元素集合的全排列
Author: EmoryHuang
Date: 2021-08-06 16:42:39
Method:
简单回溯
由于没有重复元素，因此可以直接判断元素是否在排列中
当然也可以使用额外空间记录元素是否使用
'''


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans, path, vis = [], [], [False] * len(nums)

        def dfs():
            if len(path) == len(nums):
                ans.append(path[:])
                return
            for i, num in enumerate(nums):
                if not vis[i]:
                    vis[i] = True
                    path.append(num)
                    dfs()
                    vis[i] = False
                    path.pop()

        dfs()
        return ans
