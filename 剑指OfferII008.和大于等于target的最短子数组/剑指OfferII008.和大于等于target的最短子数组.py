'''
Descroption: ��ָ Offer II 008. �ʹ��ڵ��� target �����������
Author: EmoryHuang
Date: 2021-08-07 14:36:28
Method:
��������
��������еĺʹ��� target������˵������ƶ�����������С����
'''


class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        n, l, r = len(nums), 0, 0
        ans, sum = float('inf'), 0
        while r < n:
            sum += nums[r]
            r += 1
            while sum >= target:
                ans = min(ans, r - l)
                sum -= nums[l]
                l += 1
        return 0 if ans == float('inf') else ans
