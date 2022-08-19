'''
Descroption: LeetCode 435. 无重叠区间
Author: EmoryHuang
Date: 2021-06-14 14:03:00
解题思路:
方法一：贪心思想
以数对的第二个值从小到大排序
然后比较 intervals[i][0] 和 pre 的大小

方法二：动态规划
dp[i]表示以 intervals[i] 结尾的最长链的长度
状态转移方程：dp[i] = max(dp[i], dp[j] + 1)
'''


class Solution:
    # 方法一：贪心
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], x[0]))
        pre, ans = intervals[0][1], 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < pre:
                ans += 1
                continue
            pre = intervals[i][1]
        return ans

    # 方法二：动态规划
    # def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    #     intervals.sort(key=lambda x: (x[0], x[1]))
    #     # dp[i]表示以 intervals[i] 结尾的最长链的长度
    #     dp = [1] * len(intervals)
    #     for i in range(1, len(intervals)):
    #         for j in range(i):
    #             if intervals[i][0] >= intervals[j][1]:
    #                 dp[i] = max(dp[i], dp[j] + 1)
    #     return len(intervals) - max(dp)
