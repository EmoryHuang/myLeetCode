'''
Descroption: LeetCode 673. ����������еĸ���
Author: EmoryHuang
Date: 2021-09-20 19:02:50
Method:
��̬�滮
�ڴ�ͳ����������еĻ��������ӱ���
dp[i] ��ʾ�� nums[i] ��β������������еĳ���
cnt[i] ��ʾ�� nums[i] ��β������������еĸ���
�� dp[i] == dp[j] + 1 �У�cnt[i] += cnt[j]
'''


class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        # dp[i] ��ʾ�� nums[i] ��β������������еĳ���
        # cnt[i] ��ʾ�� nums[i] ��β������������еĸ���
        dp, cnt = [0] * n, [0] * n
        l = 1
        for i in range(n):
            dp[i], cnt[i] = 1, 1
            for j in range(i):
                if nums[j] < nums[i]:
                    if dp[i] < dp[j] + 1:
                        dp[i] = dp[j] + 1
                        cnt[i] = cnt[j]
                    elif dp[i] == dp[j] + 1:
                        cnt[i] += cnt[j]  # �ۻ�
            l = max(l, dp[i])  # ��¼������г���
        ans = 0
        for i in range(n):
            if dp[i] == l:
                ans += cnt[i]
        return ans
