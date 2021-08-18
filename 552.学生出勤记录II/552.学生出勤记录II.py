'''
Descroption: LeetCode 552. 学生出勤记录 II
Author: EmoryHuang
Date: 2021-08-18 14:41:36
Method:
方法一：dfs + 记忆化搜索
暴力搜索
方法二：动态规划
dp[i][j][k]表示第i天，在缺席了j次，以及连续迟到了k次的情况下，还可以拿到奖励的出席排列的数量。
j∈{0,1}  k∈{0,1,2}，因此 dp[i][j][k]一共有六种
状态转移方程
dp[i][0][0] += dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
dp[i][0][1] += dp[i-1][0][0]
dp[i][0][2] += dp[i-1][0][1]
dp[i][1][0] += dp[i-1][0][0] + dp[i-1][0][1] + dp[i-1][0][2]
dp[i][1][1] += dp[i-1][1][0]
dp[i][1][2] += dp[i-1][1][1]
'''


class Solution:
    # 方法一：dfs + 记忆化搜索
    # def checkRecord(self, n: int) -> int:
    #     # 声明一个缓存
    #     cache = [[[-1, -1, -1], [-1, -1, -1]] for _ in range(n + 1)]

    #     def dfs(r: int, acnt: int, lcnt: int) -> int:
    #         if acnt >= 2 or lcnt >= 3: return 0
    #         if r == 0: return 1
    #         if cache[r][acnt][lcnt] != -1:
    #             return cache[r][acnt][lcnt]
    #         ans = 0
    #         mod = 10**9 + 7
    #         ans = dfs(r - 1, acnt + 1, 0) % mod  # A
    #         ans = (ans + dfs(r - 1, acnt, lcnt + 1)) % mod  # L
    #         ans = (ans + dfs(r - 1, acnt, 0)) % mod  # P
    #         cache[r][acnt][lcnt] = ans
    #         return ans

    #     return dfs(n, 0, 0)

    # 方法二：动态规划
    def checkRecord(self, n: int) -> int:
        mod = 10**9 + 7
        # dp[i][j][k]表示第i天，在缺席了j次，以及连续迟到了k次的情况下，
        # 还可以拿到奖励的出席排列的数量。
        # j∈{0,1}  k∈{0,1,2}
        # 因此 dp[i][j][k]一共有六种
        dp = [[[0, 0, 0], [0, 0, 0]] for _ in range(n + 1)]
        dp[0][0][0] = 1
        for i in range(1, n + 1):
            for j in range(2):
                for k in range(3):
                    if j == 1 and k == 0:  # A
                        # 共1种情况 (1,0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][0]) % mod
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][1]) % mod
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j - 1][2]) % mod
                    if k != 0:  # L
                        # 共4种情况 (0,1),(0,2),(1,1),(1,2)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod
                    if k == 0:  # P
                        # 共1种情况 (0,0)
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][0]) % mod
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][1]) % mod
                        dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][2]) % mod
        ans = 0
        for j in range(2):
            for k in range(3):
                ans += dp[n][j][k]
        return ans % mod
