'''
Descroption: LCP 28. �ɹ�����
Author: EmoryHuang
Date: 2021-07-08 19:42:43
����˼·:
���⣬���� + ˫ָ��
'''


class Solution:
    def purchasePlans(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        ans = 0
        nums.sort()
        while l < r:
            if nums[l] + nums[r] > target:
                r -= 1
            else:
                ans += r - l
                l += 1
        return ans % 1000000007
