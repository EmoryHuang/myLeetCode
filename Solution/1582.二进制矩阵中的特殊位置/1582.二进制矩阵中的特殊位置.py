'''
Descroption: LeetCode 1582. 二进制矩阵中的特殊位置
Author: EmoryHuang
Date: 2021-06-20 16:01:00
解题思路:
暴力方法，计算每行每列元素之和，检查行列元素之和是否为 1
'''


class Solution:
    def numSpecial(self, mat: List[List[int]]) -> int:
        m, n = len(mat), len(mat[0])
        rows = [sum(num) for num in mat]
        cols = [sum(num) for num in zip(*mat)]
        ans = 0
        for i in range(m):
            for j in range(n):
                if mat[i][j] == 1 and rows[i] == 1 and cols[j] == 1:
                    ans += 1
        return ans
