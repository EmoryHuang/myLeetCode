'''
Descroption: ��ָ Offer II 068. ���Ҳ���λ��
Author: EmoryHuang
Date: 2021-08-06 18:32:18
Method:
���ַ�Ѱ����˵�
'''


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = l + r >> 1
            # ���ַ�Ѱ����˵�
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        return l if nums[l] >= target else len(nums)
