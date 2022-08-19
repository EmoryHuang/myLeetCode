'''
Descroption: ��ָ Offer II 102. �Ӽ���Ŀ��ֵ
Author: EmoryHuang
Date: 2021-11-11 19:29:47
Method:
��̬�滮
x Ϊǰ�����Ϊ + �ļ��ϣ�y ǰ�����Ϊ - �ļ���
������Ŀ����ת��Ϊ x - y = target������ sum(nums) = x + y
����� x = (sum(nums) + target) / 2
������ת��Ϊ��Ŀ�������к�Ϊ x ����Ϸ���������01 ��������
dp[i][j] ��ʾǰ i ��������Ϊ j �ķ�����
״̬ת�Ʒ���
dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i]]
'''


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        s = sum(nums)
        if s < target or (s + target) % 2:
            return 0
        # ��Ҫ������֮��
        pos = (s + target) // 2
        dp = [0] * (pos + 1)
        dp[0] = 1
        for num in nums:
            # �������
            for i in range(pos, num - 1, -1):
                dp[i] += dp[i - num]
        return dp[pos]