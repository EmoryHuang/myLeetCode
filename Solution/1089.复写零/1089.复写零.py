'''
Descroption: LeetCode 1089. ��д��
Author: EmoryHuang
Date: 2022-06-17 20:38:30
Method:
���⣬�������飬����� 0������� 1 �� pop
'''


class Solution:
    def duplicateZeros(self, arr: List[int]) -> None:
        """
        Do not return anything, modify arr in-place instead.
        """
        i = 0
        while i < len(arr):
            if arr[i] == 0:
                arr.insert(i, 0)
                arr.pop()
                i += 1
            i += 1
