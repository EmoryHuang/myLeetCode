'''
Descroption: ��ָ Offer II 009. �˻�С�� K ��������
Author: EmoryHuang
Date: 2021-08-10 20:18:11
Method:
��������
�������飬����ǰ�˻�δ���� k������봰�ڣ������ƶ��󴰿�
'''


class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0 or k == 1: return 0
        l, r = 0, 0
        ans, mul = 0, 1
        for r in range(len(nums)):
            mul *= nums[r]
            while mul >= k:
                mul //= nums[l]
                l += 1
            ans += r - l + 1
        return ans