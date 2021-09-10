'''
Descroption: LeetCode 1846. ��С�������������������Ԫ��
Author: EmoryHuang
Date: 2021-07-15 18:47:11
����˼·:
�����������飬��һ��Ϊ 1
��arr[i]��arr[i - 1]֮����� 1������arr[i] = arr[i - 1] + 1
'''


class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        arr[0] = 1
        for i in range(1, len(arr)):
            if arr[i] - arr[i - 1] > 1:
                arr[i] = arr[i - 1] + 1
        return arr[len(arr) - 1]
