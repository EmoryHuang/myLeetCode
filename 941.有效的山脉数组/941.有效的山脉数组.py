'''
Descroption: LeetCode 941. ��Ч��ɽ������
Author: EmoryHuang
Date: 2021-06-04 13:51:00
����˼·:
�ֱ�����ң����ҵ�����б������ҵ�ɽ��
'''


class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        l, r = 0, len(arr)-1
        while l < r and arr[l] < arr[l+1]:
            l += 1
        while l < r and arr[r] < arr[r-1]:
            r -= 1
        return l == r and l != 0 and r != len(arr)-1
