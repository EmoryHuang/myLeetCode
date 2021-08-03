'''
Descroption: LeetCode 581. �����������������
Author: EmoryHuang
Date: 2021-08-03 11:04:33
Method:
����һ������
��ԭ��������֮�󣬱Ƚ�ǰ�벿�ֺͺ�벿�����򲿷ֵĳ���
��������˫ָ��
���ǿ���ͨ��Ѱ�����������������е����ֵ����Сֵȷ�����ұ߽�
'''


class Solution:
    # ����һ������
    # def findUnsortedSubarray(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     copy = nums
    #     nums = sorted(nums)
    #     if copy == nums: return 0
    #     l, r = 0, n - 1
    #     while nums[l] == copy[l]:
    #         l += 1
    #     while nums[r] == copy[r]:
    #         r -= 1
    #     return r - l + 1

    # ��������˫ָ��
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l, r = -1, -1
        minn, maxn = float('inf'), float('-inf')
        for i in range(n):
            # Ѱ��������������ұ߽�
            if nums[i] >= maxn:
                # ���򣬸���maxn
                maxn = nums[i]
            else:
                # ���򣬸��±߽�
                r = i
            # Ѱ���������������߽�
            if nums[n - i - 1] <= minn:
                minn = nums[n - i - 1]
            else:
                l = n - i - 1
        if l == -1:
            return 0
        return r - l + 1
