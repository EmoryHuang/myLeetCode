'''
Descroption: LeetCode 1877. ������������Ժ͵���Сֵ
Author: EmoryHuang
Date: 2021-07-20 19:13:13
����˼·:
���� + ����
��Ϊ��ĿҪ��������Ժ���С����ô�Ϳ���������Ȼ����βԪ���������
���ȡ���ֵ
'''


class Solution:
    def minPairSum(self, nums: List[int]) -> int:
        ans, n = 0, len(nums)
        nums.sort()
        for i in range(n // 2):
            ans = max(ans, nums[i] + nums[n - i - 1])
        return ans
