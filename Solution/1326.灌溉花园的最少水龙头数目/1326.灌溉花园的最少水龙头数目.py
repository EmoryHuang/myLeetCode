'''
Descroption: LeetCode 1326. 灌溉花园的最少水龙头数目
Author: EmoryHuang
Date: 2023-02-21 09:32:25
Method:
动态规划, 可以覆盖连续区间的最少区间数目
获取所有区间范围并排序
dp[i] 表示覆盖[0, i]需要的最少数量
状态转移方程：dp[i] = min(dp[i], dp[left] + 1)
'''


class Solution:
    def minTaps(self, n: int, ranges: List[int]) -> int:
        # 获取所有区间范围并排序
        intervals = []
        for i, r in enumerate(ranges):
            left = max(i - r, 0)
            right = min(i + r, n)
            intervals.append((left, right))
        intervals.sort()
        # dp[i] 表示覆盖[0, i]需要的最少数量
        dp = [inf] * (n + 1)
        dp[0] = 0
        for l, r in intervals:
            if dp[l] == inf:
                return -1
            for j in range(l, r + 1):
                dp[j] = min(dp[j], dp[l] + 1)
        return dp[n]