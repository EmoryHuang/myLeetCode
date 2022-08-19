'''
Descroption: LeetCode 413. �Ȳ����л���
Author: EmoryHuang
Date: 2021-08-10 13:08:30
Method:
��̬�滮
������nums[i]��β�ĵȲ����еĸ���
'''


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 3:
            return 0
        # ������nums[i]��β�ĵȲ����еĸ���
        ans, cnt = 0, 0
        for i in range(2, n):
            if nums[i] + nums[i - 2] == 2 * nums[i - 1]:
                cnt += 1
                ans += cnt
            else:
                cnt = 0
        return ans