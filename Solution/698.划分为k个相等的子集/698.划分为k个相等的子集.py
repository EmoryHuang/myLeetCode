'''
Descroption: LeetCode 698. 划分为k个相等的子集
Author: EmoryHuang
Date: 2022-09-20 13:53:42
Method:
dfs + 状态压缩 + 剪枝
使用 used 记录使用过的数字，cur 记录当前和
dfs 遍历所有可能，判断数字是否使用过，未使用则继续搜索
'''


class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        total = sum(nums)
        if total % k:
            return False
        nums.sort()
        n, t = len(nums), total // k
        if nums[-1] > t:
            return False

        @cache
        def dfs(used, cur):
            # used 记录使用过的数字
            # cur 记录当前和
            if used == 0:
                return True

            for i in range(n):
                # 超过则停止
                if nums[i] + cur > t:
                    break
                # 判断数字是否使用过，未使用则继续搜索
                if used >> i & 1 and dfs(used^(1 << i), (nums[i] + cur) % t):
                    return True
            return False

        return dfs((1 << n) - 1, 0)