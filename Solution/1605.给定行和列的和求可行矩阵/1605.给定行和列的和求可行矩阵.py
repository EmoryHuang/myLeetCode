'''
Descroption: LeetCode 1605. �����к��еĺ�����о���
Author: EmoryHuang
Date: 2021-09-14 16:07:18
Method:
̰��
ʹ�� rowCur, colCur �ֱ��¼��ǰÿ��ÿ�еĺ�
����ÿ��λ�ã�ȡ���е�ǰ�������������Ľ�Сֵ
'''


class Solution:
    def restoreMatrix(self, rowSum: List[int], colSum: List[int]) -> List[List[int]]:
        row, col = len(rowSum), len(colSum)
        ans = [[0] * col for _ in range(row)]
        # rowCur, colCur �ֱ��¼��ǰÿ��ÿ�еĺ�
        rowCur, colCur = [0] * row, [0] * col
        for i in range(row):
            for j in range(col):
                # ȡ���е�ǰ�������������Ľ�Сֵ
                num = min(rowSum[i] - rowCur[i], colSum[j] - colCur[j])
                ans[i][j] = num
                rowCur[i] += num
                colCur[j] += num
        return ans
