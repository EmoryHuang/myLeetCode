'''
Descroption: LeetCode 1024. 视频拼接
Author: EmoryHuang
Date: 2021-10-20 20:24:35
Method:
方法一：动态规划
dp[i] 表示将区间 [0, i) 覆盖需要的最小区间
状态转移方程：dp[i] = min(dp[i], dp[l] + 1)

方法二：贪心
使用 maxr[i] 表示左端点 i 处能够到达的最右位置
贪心遍历每个位置，到达当前位置能够达到的最远位置
'''


class Solution:
    # 方法一：动态规划
    # def videoStitching(self, clips: List[List[int]], time: int) -> int:
    #     # dp[i] 表示将区间 [0, i) 覆盖需要的最小区间
    #     dp = [float('inf')] * (time + 1)
    #     dp[0] = 0
    #     for i in range(1, time + 1):
    #         for l, r in clips:
    #             if l < i <= r:
    #                 dp[i] = min(dp[i], dp[l] + 1)
    #     if dp[time] == float('inf'):
    #         return -1
    #     return dp[time]

    # 方法二：贪心
    def videoStitching(self, clips: List[List[int]], time: int) -> int:
        ans, pre, last = 0, 0, 0
        # maxr[i] 表示左端点 i 处能够到达的最右位置
        maxr = [0] * time
        for l, r in clips:
            if l < time:
                maxr[l] = max(maxr[l], r)
        # 遍历每个位置
        for i in range(time):
            last = max(last, maxr[i])
            if i == last:
                # 下一个位置无法被覆盖
                return -1
            if i == pre:
                # 到达了上一个位置
                pre = last
                ans += 1
        return ans