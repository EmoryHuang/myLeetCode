'''
Descroption: ��ָ Offer II 007. �����к�Ϊ 0 ��������
Author: EmoryHuang
Date: 2021-08-04 19:25:55
Method:
��ָ�룬����
�������������Ȼ����������ָ��ֱ�ִ��Ԫ��
ע�������ظ�����
'''


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if not nums or n < 3:
            return []
        nums.sort()
        if nums[0] > 0:
            return []
        ans = []
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                if nums[i] + nums[j] + nums[k] > 0:
                    k -= 1
                elif nums[i] + nums[j] + nums[k] < 0:
                    j += 1
                else:
                    ans.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    j += 1
                    k -= 1
        return ans