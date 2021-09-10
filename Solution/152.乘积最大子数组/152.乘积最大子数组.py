'''
Descroption: LeetCode 152. �˻����������
Author: EmoryHuang
Date: 2021-07-11 13:57:44
����˼·:
��������ʱ���㵱ǰ���ֵ�����ϸ���
���ڴ��ڸ�������ô�ᵼ�����ı���С�ģ���С�ı����ġ���˻���Ҫά����ǰ��Сֵ
'''


class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        dpmax = dpmin = ans = nums[0]
        for i in range(1, len(nums)):
            tmpmax, tmpmin = dpmax, dpmin
            dpmax = max(nums[i], tmpmin * nums[i], tmpmax * nums[i])
            dpmin = min(nums[i], tmpmin * nums[i], tmpmax * nums[i])
            ans = max(ans, dpmax)
        return ans
