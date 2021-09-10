'''
Descroption: LeetCode 1572. ����Խ���Ԫ�صĺ�
Author: EmoryHuang
Date: 2021-08-14 14:18:35
Method:
��Ϊ�������ξ������Կ���ֱ�ӵõ��ĸ�λ�õ�ֵ������һ�鼴��
��Ϊ����Ԫ�أ�ֻ��Ҫ��һ��
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
