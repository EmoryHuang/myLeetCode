'''
Descroption: LeetCode 598. ��Χ��� II
Author: EmoryHuang
Date: 2021-09-13 16:16:13
Method:
���⣬�����޸ĵķ�Χʼ����һ�������Ͻǿ�ʼ�ľ���
��ôֻҪ�õ���С�Ĳ������м���ȷ�����ֵ���ڵľ���
'''


class Solution:
    def maxCount(self, m: int, n: int, ops: List[List[int]]) -> int:
        row, col = m, n
        for i, j in ops:
            row, col = min(row, i), min(col, j)
        return row * col
