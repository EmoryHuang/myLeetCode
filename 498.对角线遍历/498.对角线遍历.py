'''
Descroption: LeetCode 498. �Խ��߱���
Author: EmoryHuang
Date: 2021-08-12 19:38:43
Method:
ģ��
�жϵ�ǰ�Խ��ߵĲ�����Ȼ������µ����ϻ��ߴ����ϵ�����
'''


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        if len(mat) == 0:
            return []
        m, n = len(mat), len(mat[0])
        row, col = 0, 0
        ans = []
        # �Խ��߱����Ĳ���
        for x in range(m * n):
            ans.append(mat[row][col])
            if (row + col) % 2 == 0:
                if col == n - 1:  # ���һ��
                    row += 1
                elif row == 0:  # ��һ��
                    col += 1
                else:  # ���µ�����
                    row, col = row - 1, col + 1
            else:
                if row == m - 1:  # ���һ��
                    col += 1
                elif col == 0:  # ��һ��
                    row += 1
                else:  # ���ϵ�����
                    row, col = row + 1, col - 1
        return ans
