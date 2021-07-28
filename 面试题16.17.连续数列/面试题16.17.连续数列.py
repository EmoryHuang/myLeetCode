'''
Descroption: ������ 16.17. ��������
Author: EmoryHuang
Date: 2021-07-28 19:14:13
Method:
��̬�滮
'''


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre, ans = 0, nums[0]
        for num in nums:
            pre = max(pre + num, num)
            ans = max(ans, pre)
        return ans