'''
Descroption: LeetCode 1380. 矩阵中的幸运数
Author: EmoryHuang
Date: 2021-08-20 19:16:44
Method:
遍历矩阵，找到每行的最小值和每列的最大值
然后再次遍历，判断当前元素是否是当前行的最小值和列的最大值
'''


class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        m, n = len(matrix), len(matrix[0])
        row, col = [float('inf')] * m, [0] * n
        for i in range(m):
            for j in range(n):
                row[i] = min(row[i], matrix[i][j])
                col[j] = max(col[j], matrix[i][j])
        ans = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == row[i] == col[j]:
                    ans.append(matrix[i][j])
        return ans