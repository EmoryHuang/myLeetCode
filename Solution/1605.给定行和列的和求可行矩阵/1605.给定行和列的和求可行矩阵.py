'''
Descroption: LeetCode 1605. 给定行和列的和求可行矩阵
Author: EmoryHuang
Date: 2021-09-14 16:07:18
Method:
贪心
使用 rowCur, colCur 分别记录当前每行每列的和
对于每个位置，取行列当前最大可以填充的数的较小值
'''


class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        row, col = len(rowSum), len(colSum)
        ans = [[0] * col for _ in range(row)]
        # rowCur, colCur 分别记录当前每行每列的和
        rowCur, colCur = [0] * row, [0] * col
        for i in range(row):
            for j in range(col):
                # 取行列当前最大可以填充的数的较小值
                num = min(rowSum[i] - rowCur[i], colSum[j] - colCur[j])
                ans[i][j] = num
                rowCur[i] += num
                colCur[j] += num
        return ans
