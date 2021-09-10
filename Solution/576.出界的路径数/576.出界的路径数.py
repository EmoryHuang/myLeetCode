'''
Descroption: LeetCode 576. 出界的路径数
Author: EmoryHuang
Date: 2021-08-15 11:47:39
Method:
动态规划
刚开始没想直接dfs,然而超时了...
dp[i][j][k]表示(i,j)位置上k步内移除边界的路径数
状态转移方程
dp[i][j][k] = dp[i-1][j][k-1] + dp[i+1][j][k-1] + dp[i][j-1][k-1] + dp[i][j+1][k-1]
'''


class Solution:
    # 无空间优化
    # def findPaths(self, m: int, n: int, maxMove: int, startRow: int,
    #               startColumn: int) -> int:
    #     if maxMove == 0:
    #         return 0
    #     mod = 10**9 + 7
    #     dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
    #     dp = [[[0] * (maxMove + 1) for i in range(n)] for j in range(m)]
    #     for k in range(1, maxMove + 1):
    #         for x in range(m):
    #             for y in range(n):
    #                 for i in range(4):
    #                     newx, newy = x + dx[i], y + dy[i]
    #                     if not 0 <= newx < m or not 0 <= newy < n:
    #                         dp[x][y][k] += 1
    #                     else:
    #                         dp[x][y][k] = (dp[x][y][k] + dp[newx][newy][k - 1]) % mod
    #     return dp[startRow][startColumn][maxMove]

    # 空间优化
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int,
                  startColumn: int) -> int:
        if maxMove == 0:
            return 0
        mod = 10**9 + 7
        dx, dy = [0, -1, 0, 1], [1, 0, -1, 0]
        dp = [[0] * n for _ in range(m)]
        for k in range(1, maxMove + 1):
            # 保存第 k-1 步的结果
            tmp = [[0] * n for _ in range(m)]
            for x in range(m):
                for y in range(n):
                    for i in range(4):
                        newx, newy = x + dx[i], y + dy[i]
                        if not 0 <= newx < m or not 0 <= newy < n:
                            tmp[x][y] += 1
                        else:
                            tmp[x][y] = (tmp[x][y] + dp[newx][newy]) % mod
            dp = tmp
        return dp[startRow][startColumn]
