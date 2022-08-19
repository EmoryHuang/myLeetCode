'''
Descroption: ��ָ Offer II 090. ���η���͵��
Author: EmoryHuang
Date: 2021-08-09 20:04:36
Method:
��̬�滮
��һ�������һ������ͬʱ����������һ����ʱ�����һ�������ɲ�������һ�����ͬ��
dp[i] ��ʾ����i������Ϊֹ��͵���������
״̬ת�Ʒ��̣�dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
'''


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        ans, dp = 0, [0] * n
        # ��͵��һ��
        dp[0], dp[1] = 0, nums[1]
        for i in range(2, n):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        ans = dp[n - 1]
        # ��͵���һ��
        dp[0], dp[1] = nums[0], max(nums[0], nums[1])
        for i in range(2, n - 1):
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1])
        return max(ans, dp[n - 2])
