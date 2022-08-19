'''
Descroption: LeetCode 594. ���г������
Author: EmoryHuang
Date: 2021-10-13 08:52:19
Method:
����һ������ + ˫ָ��
�����������в���ֻҪ��������ȣ���˿���ֱ������Ȼ��ͨ��˫ָ���ҵ����г�����еĳ���

����������ϣ��
ʹ�ù�ϣ���¼Ԫ�س��ֵĴ�����num ���Ժ� num + 1 ��ɺ�г������
Ҳ������������ֵΪ 1 ����������ܸ���
'''


class Solution:
    # ����һ������ + ˫ָ��
    # def findLHS(self, nums: List[int]) -> int:
    #     nums.sort()
    #     l, r, ans = 0, 0, 0
    #     for r in range(len(nums)):
    #         while nums[r] - nums[l] > 1:
    #             l += 1
    #         if nums[r] - nums[l] == 1:
    #             ans = max(ans, r - l + 1)
    #     return ans

    # ����������ϣ��
    def findLHS(self, nums: List[int]) -> int:
        ans = 0
        hash = Counter(nums)
        for num in nums:
            if num + 1 in hash:
                ans = max(ans, hash[num] + hash[num + 1])
        return ans
