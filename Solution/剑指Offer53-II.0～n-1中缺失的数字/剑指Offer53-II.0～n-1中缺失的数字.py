'''
Descroption: ��ָ Offer 53 - II. 0��n-1��ȱʧ������
Author: EmoryHuang
Date: 2021-07-23 18:46:48
����˼·:
���ַ�Ѱ����˵�
'''


class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        while l <= r:
            mid = l + r >> 1
            if nums[mid] == mid:
                # ȱʧ���������Ұ벿��
                l = mid + 1
            else:
                # ȱʧ����������벿��
                r = mid - 1
        return l
