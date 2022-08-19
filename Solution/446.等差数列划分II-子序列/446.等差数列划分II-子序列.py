'''
Descroption: LeetCode 446. �Ȳ����л��� II - ������
Author: EmoryHuang
Date: 2021-08-11 14:27:29
Method:
��̬�滮 + ��ϣ��
dp[i][d] ��ʾ�� nums[i] ��β�ģ�����Ϊ d �ĵȲ����и���
״̬ת�Ʒ��̣�dp[i][d] += dp[j][d] + 1
'''


class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        # dp[i] ��ÿ��Ԫ�ؾ�Ϊ��ϣ�� {d: cnt}
        # d ��ʾ�Ȳ����еĲ�ֵ
        # cnt ��ʾ�� nums[i] ��β�ģ�����Ϊ d �ĵȲ����и���
        dp = [defaultdict(int) for _ in range(n)]
        for i in range(n):
            for j in range(i):
                # ���� nums[i] �� nums[j] ֮��Ĳ�ֵ
                d = nums[i] - nums[j]
                # �� nums[j] ��β�ģ�����Ϊ d �ĵȲ����и���
                cnt = dp[j][d]
                ans += cnt
                # ��Ϊ nums[i] �� nums[j] �Ĳ�ֵҲΪ d������������ 1
                dp[i][d] += cnt + 1
        return ans