'''
Descroption: ��ָ Offer II 069. ɽ������Ķ���
Author: EmoryHuang
Date: 2021-08-06 18:27:47
Method:
���ַ�Ѱ����˵�
'''


class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        l, r = 0, len(arr) - 1
        while l < r:
            mid = l + r >> 1
            # ���ַ�Ѱ����˵�
            if arr[mid] >= arr[mid + 1]:
                r = mid
            else:
                l = mid + 1
        return l
