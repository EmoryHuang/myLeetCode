'''
Descroption: ��ָ Offer 53 - I. �����������в������� I
Author: EmoryHuang
Date: 2021-07-16 18:32:41
����˼·:
���ַ�Ѱ����˵㣬Ȼ�����˵㿪ʼѰ�� target
'''


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        l, r = 0, len(nums) - 1
        while l < r:
            mid = (l + r) // 2
            if nums[mid] >= target:
                r = mid
            else:
                l = mid + 1
        ans = 0
        while l < len(nums) and nums[l] == target:
            ans += 1
            l += 1
        return ans
