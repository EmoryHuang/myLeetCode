'''
Descroption: LeetCode 724. Ѱ������������±�
Author: EmoryHuang
Date: 2021-06-16 14:25:00
����˼·:
���⣬�������飬��ȥ����ǰԪ�غ�ǰ�벿�ֺ�Ϊ����Ԫ�ص�һ���򷵻��±�
'''


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        cur, s = 0, sum(nums)
        for i, num in enumerate(nums):
            if 2 * cur + num == s:
                return i
            cur += num
        return -1