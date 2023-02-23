'''
Descroption: LeetCode 1139. 最大的以 1 为边界的正方形
Author: EmoryHuang
Date: 2023-02-17 09:24:20
Method:
动态规划
记录以x,y为起点，左侧/上侧连续1的最大数量
枚举可以构成正方形的边长
'''


class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        m, n = len(grid), len(grid[0])
        maxboard = 0
        # 以x,y为起点，左侧/上侧连续1的最大数量
        left = [[0] * (n + 1) for _ in range(m + 1)]
        up = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                if grid[i - 1][j - 1]:
                    left[i][j] = left[i][j - 1] + 1
                    up[i][j] = up[i - 1][j] + 1
                    board = min(left[i][j], up[i][j])
                    while left[i - board + 1][j] < board or up[i][j - board + 1] < board:
                        board -= 1
                    maxboard = max(maxboard, board)
        return maxboard**2