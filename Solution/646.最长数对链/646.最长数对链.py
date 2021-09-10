'''
Descroption: LeetCode 646. 最长数对链
Author: EmoryHuang
Date: 2021-06-14 13:55:00
解题思路:
方法一：贪心思想，
以数对的第二个值从小到大排序
然后比较 pairs[i][0] 和 pre 的大小
 *
方法二：动态规划
dp[i]表示以 pairs[i] 结尾的最长链的长度
状态转移方程：dp[i] = max(dp[i], dp[j] + 1)
'''


class Solution:
    # 方法一：贪心
    # def findLongestChain(self, pairs: List[List[int]]) -> int:
    #     pairs.sort(key=lambda x: (x[1], x[0]))
    #     pre, ans = pairs[0][1], 1
    #     for i in range(1, len(pairs)):
    #         if pairs[i][0] > pre:
    #             ans += 1
    #             pre = pairs[i][1]
    #     return ans

    # 方法二：动态规划
    def findLongestChain(self, pairs: List[List[int]]) -> int:
        pairs.sort(key=lambda x: (x[0], x[1]))
        # dp[i]表示以 pairs[i] 结尾的最长链的长度
        dp = [1] * len(pairs)
        for i in range(1, len(pairs)):
            for j in range(i):
                if pairs[i][0] > pairs[j][1]:
                    dp[i] = max(dp[i], dp[j] + 1)
        return max(dp)
