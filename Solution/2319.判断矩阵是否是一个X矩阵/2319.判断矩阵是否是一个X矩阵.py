'''
Descroption: LeetCode 2319. 判断矩阵是否是一个 X 矩阵
Author: EmoryHuang
Date: 2023-01-31 08:39:15
Method:
简单题，遍历矩阵，判断对角线上的原始是否为0
'''


class Solution:
    def checkXMatrix(self, grid: List[List[int]]) -> bool:
        n = len(grid)
        for i in range(n):
            for j in range(n):
                if i == j or (i + j) == (n - 1):
                    if grid[i][j] == 0:
                        return False
                elif grid[i][j]:
                    return False
        return True