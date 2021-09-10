'''
Descroption: LeetCode 498. 对角线遍历
Author: EmoryHuang
Date: 2021-08-12 19:38:43
Method:
模拟
判断当前对角线的层数，然后从左下到右上或者从右上到左下
'''


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if len(mat) == 0:
            return []
        m, n = len(mat), len(mat[0])
        row, col = 0, 0
        ans = []
        # 对角线遍历的层数
        for x in range(m * n):
            ans.append(mat[row][col])
            if (row + col) % 2 == 0:
                if col == n - 1:  # 最后一列
                    row += 1
                elif row == 0:  # 第一行
                    col += 1
                else:  # 左下到右上
                    row, col = row - 1, col + 1
            else:
                if row == m - 1:  # 最后一行
                    col += 1
                elif col == 0:  # 第一列
                    row += 1
                else:  # 右上到左下
                    row, col = row + 1, col - 1
        return ans
