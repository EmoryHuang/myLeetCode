'''
Descroption: LeetCode 795. 区间子数组个数
Author: EmoryHuang
Date: 2021-08-15 12:24:59
Method:
动态规划
使用count计算数组中小于等于x的子数组的数量
最后的结果即为count(right) - count(left - 1)
'''


class Solution:
    def numSubarrayBoundedMax(self, nums: List[int], left: int, right: int) -> int:
        def count(x: int) -> int:
            # 计算数组中小于等于x的子数组的数量
            ans = cur = 0
            for num in nums:
                cur = cur + 1 if num <= x else 0
                ans += cur
            return ans

        return count(right) - count(left - 1)
