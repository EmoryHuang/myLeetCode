'''
Descroption: LeetCode 907. 子数组的最小值之和
Author: EmoryHuang
Date: 2022-10-28 09:30:20
Method:
动态规划
dp[i] 表示以 i 为结尾的子数组最小值之和
维护一个单调栈，求出元素 x 的左边第一个比它小的元素
即求出以 x 为最右且最小的子序列的最大长度 k
状态转移方程：dp[i] = dp[i - k] + k * arr[i]
'''


class Solution:

    def sumSubarrayMins(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        n, ans = len(arr), 0
        stack = []
        # dp[i] 表示以 i 为结尾的子数组最小值之和
        dp = [0] * n
        # 维护一个单调栈，求出元素 x 的左边第一个比它小的元素
        # 即求出以 x 为最右且最小的子序列的最大长度 k
        for i, x in enumerate(arr):
            while stack and arr[stack[-1]] > x:
                stack.pop()
            k = i - stack[-1] if stack else i + 1
            dp[i] = k * x + (dp[i - k] if stack else 0)
            ans = (ans + dp[i]) % MOD
            stack.append(i)
        return ans