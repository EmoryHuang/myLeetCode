'''
Descroption: LeetCode 1619. ɾ��ĳЩԪ�غ�������ֵ
Author: EmoryHuang
Date: 2021-09-22 20:59:38
Method:
���⣬ȥ��ǰ�� 5% ������ֵ
'''


class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        n = len(arr)
        d = n // 20
        return sum(arr[d:(n - d)]) / (n - 2 * d)
