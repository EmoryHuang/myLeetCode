'''
Descroption: LeetCode 2008. 出租车的最大盈利
Author: EmoryHuang
Date: 2021-10-08 20:25:37
Method:
方法一：动态规划
dp[i] 表示以 i 结尾的位置能得到的最大利润
若不载客，则有 dp[i] = dp[i - 1]
若载客，则选择当前位置能获得的最大利润 dp[i] = max(dp[i], dp[start] + profit)

方法二：动态规划 + 二分
状态转移方程: dp[i] = max(dp[i - 1], dp[r] + end - start + tip)
使用二分查找，寻找距离当前终点最近的起点位置
'''


class Solution:
    # 方法一：动态规划
    # def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
    #     # dp[i] 表示以 i 结尾的位置能得到的最大利润
    #     dp = [0] * (n + 1)
    #     d = defaultdict(list)
    #     for start, end, tip in rides:
    #         d[end].append([start, end - start + tip])
    #     for i in range(1, n + 1):
    #         # 不载客
    #         dp[i] = dp[i - 1]
    #         for start, w in d[i]:
    #             dp[i] = max(dp[i], dp[start] + w)
    #     return dp[n]

    # 方法二：动态规划 + 二分
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        m = len(rides)
        # 按终点排序
        rides.sort(key=lambda x: x[1])
        dp = [0] * (m + 1)
        for i in range(1, m + 1):
            start, end, tip = rides[i - 1]
            # 二分法寻找距离当前终点最近的起点位置
            l, r = 0, i - 1
            while l < r:
                mid = l + r + 1 >> 1
                if rides[mid - 1][1] <= start:
                    l = mid
                else:
                    r = mid - 1
            dp[i] = max(dp[i - 1], dp[r] + end - start + tip)
        return dp[m]
