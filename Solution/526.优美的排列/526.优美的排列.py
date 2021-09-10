'''
Descroption: LeetCode 526. 优美的排列
Author: EmoryHuang
Date: 2021-08-16 15:40:03
Method:
方法一：状态压缩 + 回溯
使用二进制串记录数字的访问状态
回溯法进行深度优先遍历，直到访问完所有数

方法二：状态压缩 + dp
dp[i][state] 表示前i个数状态为state的方案数
枚举i个数,这i个数的状态state以及第i个数的值k
状态转移方程：dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))]
其中，state & (~(1 << (k - 1))) 将 state 中的第 k 位置 0，也就是未选取 k 时的状态
'''


class Solution:
    # 方法一：状态压缩 + 回溯
    # def countArrangement(self, n: int) -> int:
    #     def dfs(i: int, vis: int) -> int:
    #         # 全部访问
    #         if vis == (1 << n) - 1:
    #             return 1
    #         ans = 0
    #         for ind in range(n):
    #             # 跳过已访问过的数
    #             if (1 << ind) & vis:
    #                 continue
    #             # 如果是优美的排列
    #             if i % (ind + 1) == 0 or (ind + 1) % i == 0:
    #                 vis ^= (1 << ind)
    #                 ans += dfs(i + 1, vis)
    #                 vis ^= (1 << ind)
    #         return ans

    #     return dfs(1, 0)

    # 方法二：状态压缩 + dp
    def countArrangement(self, n: int) -> int:
        mask = 1 << n
        # dp[i][state] 表示前i个数状态为state的方案数
        dp = [[0] * (mask) for _ in range(n + 1)]
        dp[0][0] = 1
        # 枚举所有位置
        for i in range(1, n + 1):
            # 枚举所有状态
            for state in range(mask):
                # 枚举位置 i 的数是 k
                for k in range(1, n + 1):
                    # 位置 k 必须是 1
                    if (state >> (k - 1)) & 1 == 0:
                        continue
                    if i % k != 0 and k % i != 0:
                        continue
                    # state & (~(1 << (k - 1))) 表示将 state 中的第 k 位置 0
                    # 也就是未选取 k 时的状态
                    dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))]
        return dp[n][mask - 1]
