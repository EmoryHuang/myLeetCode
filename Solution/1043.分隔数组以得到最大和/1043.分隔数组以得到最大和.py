'''
Descroption: LeetCode 1043. 分隔数组以得到最大和
Author: EmoryHuang
Date: 2022-09-13 21:06:10
Method:
动态规划
dp[i]表示前i个数进行分割的最大值
状态转移方程：dp[i] = max(dp[i], dp[j] + (i - j) * submax)
'''


class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            submax = -1 # 局部最大值
            for j in range(i - 1, -1, -1):
                if i - j <= k:
                    submax = max(submax, arr[j])
                    dp[i] = max(dp[i], dp[j] + (i - j) * submax)
        return dp[n]
