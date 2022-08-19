'''
Descroption: LeetCode 1975. 最大方阵和
Author: EmoryHuang
Date: 2021-09-23 19:20:08
Method:
如果负数的数量是偶数，那么所有负数都能变成正数
如果负数的数量是奇数，那么只需要记录绝对值最小的数
'''


class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        ans = 0
        # 记录负数的数量，绝对值最小的数
        cnt, m = 0, float('inf')
        for i in range(n):
            for j in range(n):
                ans += abs(matrix[i][j])
                if matrix[i][j] <= 0:
                    cnt += 1
                m = min(m, abs(matrix[i][j]))
        if cnt % 2 == 0:
            return ans
        return ans - 2 * m
