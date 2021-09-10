'''
Descroption: LeetCode 1572. 矩阵对角线元素的和
Author: EmoryHuang
Date: 2021-08-14 14:18:35
Method:
因为是正方形矩阵，所以可以直接得到四个位置的值，遍历一遍即可
若为中心元素，只需要加一次
'''


class Solution:
    def diagonalSum(self, mat: List[List[int]]) -> int:
        n = len(mat)
        ans = 0
        for i in range(n):
            if i == n - i - 1:
                ans += mat[i][i]
            else:
                ans += mat[i][i] + mat[i][n - i - 1]
        return ans
