'''
Descroption: LeetCode 1380. �����е�������
Author: EmoryHuang
Date: 2021-08-20 19:16:44
Method:
���������ҵ�ÿ�е���Сֵ��ÿ�е����ֵ
Ȼ���ٴα������жϵ�ǰԪ���Ƿ��ǵ�ǰ�е���Сֵ���е����ֵ
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