'''
Descroption: LeetCode 1365. �ж���С�ڵ�ǰ���ֵ�����
Author: EmoryHuang
Date: 2021-06-22 19:49:00
����˼·:
cnt[i] ��ʾ���� i ���ֵĴ�����
��ô�������� i ���ԣ�С��������Ŀ��Ϊ cnt[0...i-1] ���ܺ�
'''


class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        cnt = [0] * 101
        for num in nums:
            cnt[num] += 1
        for i in range(1, 101):
            cnt[i] += cnt[i - 1]
        ans = []
        for i in range(len(nums)):
            if nums[i] == 0:
                ans.append(0)
            else:
                ans.append(cnt[nums[i] - 1])
        return ans
