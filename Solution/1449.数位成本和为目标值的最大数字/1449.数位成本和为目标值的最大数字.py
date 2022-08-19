'''
Descroption: LeetCode 1449. 数位成本和为目标值的最大数字
Author: EmoryHuang
Date: 2021-06-12 21:58:00
解题思路:
完全背包问题
若两个整数位数不同，位数更多的整数必然大于位数小的整数。
因此我们需要先计算出可以得到的整数的最大位数
dp[j]表示总成本恰好为 j 时最大位数
状态转移方程：dp[j] = max(dp[j], dp[j - cost] + 1)
应该尽可能让高位的数值越大越好，
因此我们可以从数值 9 开始往数值 1 遍历，如果状态能够由该数值转移而来，则选择该数值
'''


class Solution:
    def largestNumber(self, cost: List[int], target: int) -> str:
        # dp[j]表示总成本恰好为 j 时最大位数
        dp = [float("-inf")] * (target + 1)
        dp[0] = 0
        for c in cost:
            for j in range(c, target + 1):
                dp[j] = max(dp[j], dp[j - c] + 1)
        if dp[target] < 0:
            return "0"
        ans = ""
        j = target
        # 从后往前遍历，cost最长为9
        for i in range(8, -1, -1):
            while j >= cost[i] and dp[j] == dp[j - cost[i]] + 1:
                ans += str(i + 1)
                j -= cost[i]
        return ans
