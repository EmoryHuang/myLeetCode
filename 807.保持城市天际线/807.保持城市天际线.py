'''
Descroption: LeetCode 807. 保持城市天际线
Author: EmoryHuang
Date: 2021-06-19 14:41:00
解题思路:
求出行列的最大值元素，对于每个grid[i][j]只需要取所在行列最大值的最小值即可
'''


class Solution:
    def maxIncreaseKeepingSkyline(self, grid: List[List[int]]) -> int:
        n = len(grid)
        row, col = [0] * n, [0] * n
        for i in range(n):
            for j in range(n):
                row[i] = max(row[i], grid[i][j])
                col[j] = max(col[j], grid[i][j])
        # 简洁写法
        # row = [max(i) for i in grid]
        # col = [max(j) for j in zip(*grid)]
        ans = 0
        for i in range(n):
            for j in range(n):
                ans += min(row[i], col[j]) - grid[i][j]
        return ans