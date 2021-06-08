'''
Descroption: LeetCode 1049. 最后一块石头的重量 II
Author: EmoryHuang
Date: 2021-06-08 15:22:00
解题思路:
01背包问题
该题可以抽象为将 n 块石头分为两堆，而后求两堆石头重量总和的最小差值
具体来说，从 stones 数组中选择，凑成总和不超过 sum/2 的最大价值。
'''


class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        s = sum(stones)
        # 背包容量上限为石头总重量的一半
        dp = [0 for _ in range(s // 2 + 1)]
        for stone in stones:
            for j in range(s // 2, stone - 1, -1):  # 倒序遍历
                dp[j] = max(dp[j], dp[j - stone] + stone)
        return s - dp[s // 2] * 2
