'''
Descroption: LeetCode 1235. 规划兼职工作
Author: EmoryHuang
Date: 2022-10-22 09:46:25
Method:
动态规划
按结束时间从小到大进行排序，dp[i] 表示前 i 份工作的最大利润
状态转移方程 dp[i] = max(dp[i - 1], dp[k] + profit[i - 1])
其中 k 表示满足结束时间小于等于第 i−1 份工作开始时间的兼职工作数量
'''


class Solution:

    def jobScheduling(self, startTime: List[int], endTime: List[int],
                      profit: List[int]) -> int:
        n = len(startTime)
        # 按结束时间从小到大进行排序
        jobs = sorted(zip(startTime, endTime, profit), key=lambda x: x[1])
        # dp[i] 表示前 i 份工作的最大利润
        dp = [0] * (n + 1)
        for i in range(1, n + 1):
            # 状态转移方程 dp[i] = max(dp[i - 1], dp[k] + profit[i - 1])
            # 其中 k 表示满足结束时间小于等于第 i−1 份工作开始时间的兼职工作数量
            k = bisect_right(jobs, jobs[i - 1][0], hi=i, key=lambda x: x[1])
            dp[i] = max(dp[i - 1], dp[k] + jobs[i - 1][2])
        return dp[n]