'''
Descroption: LeetCode 1252. 奇数值单元格的数目
Author: EmoryHuang
Date: 2021-07-15 20:06:16
解题思路:
模拟法，模拟对每行每列的加法，然后遍历统计奇数的个数
'''


class Solution:
    def oddCells(self, m: int, n: int, indices: List[List[int]]) -> int:
        mat = [[0] * n for _ in range(m)]
        for row, col in indices:
            for i in range(n):
                mat[row][i] += 1
            for i in range(m):
                mat[i][col] += 1
        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] % 2 == 1:
                    ans += 1
        return ans
