'''
Descroption: LeetCode 2044. 统计按位或能得到最大值的子集数目
Author: EmoryHuang
Date: 2022-03-15 10:13:55
Method:
方法一：二进制枚举
二进制枚举，使用 n 位二进制记录 nums 中的每个数据是否被选择
同时维护按位与能得到的最大值

方法二：dfs
暴力枚举每个 num 是否被选择，并记录能得到的最大值
'''

class Solution:
    # 方法一：二进制枚举
    def countMaxOrSubsets(self, nums: List[int]) -> int:
        n = len(nums)
        ans, max_num = 0, 0
        for s in range(1 << n):
            num = 0
            for i in range(n):
                if ((s >> i) & 1 == 1):
                    num |= nums[i]
            if num > max_num:
                max_num = num
                ans = 1
            elif max_num == num:
                ans += 1
        return ans

    # # 方法二：dfs
    # def countMaxOrSubsets(self, nums: List[int]) -> int:
    #     def dfs(idx, num):
    #         if idx == len(nums):
    #             if num > self.max_num:
    #                 self.max_num = num
    #                 self.ans = 1
    #             elif self.max_num == num:
    #                 self.ans += 1
    #             return
    #         dfs(idx + 1, num)
    #         dfs(idx + 1, num | nums[idx])

    #     self.ans, self.max_num = 0, 0
    #     dfs(0, 0)
    #     return self.ans
