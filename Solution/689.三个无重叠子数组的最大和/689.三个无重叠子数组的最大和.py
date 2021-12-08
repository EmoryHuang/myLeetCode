'''
Descroption: LeetCode 689. �������ص������������
Author: EmoryHuang
Date: 2021-12-08 19:45:56
Method:
����һ����������
ͬʱ�����������ڣ�����¼����

����������̬�滮
dp[i][j] ��ʾǰ i ��Ԫ���У�j �������������
�����ŷ����а��� num[i], ֻ���� [0, i - k] ��ѡ j - 1 ��������
�����ŷ����в����� num[i], dp[i][j] = dp[i - 1][j]
״̬ת�Ʒ��̣�dp[i][j] = max(dp[i - 1][j], dp[i - k][j - 1] + sum[i - k + 1] - sum[i + 1])
'''


class Solution:
    # ����һ����������
    # def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
    #     sum1, max_sum1, max_sum1_idx = 0, 0, 0
    #     sum2, max_sum12, max_sum12_idx = 0, 0, ()
    #     sum3, max_sum123 = 0, 0
    #     for i in range(2 * k, len(nums)):
    #         sum1 += nums[i - 2 * k]
    #         sum2 += nums[i - k]
    #         sum3 += nums[i]
    #         if i >= 3 * k - 1:
    #             if sum1 > max_sum1:
    #                 max_sum1 = sum1
    #                 max_sum1_idx = i - 3 * k + 1
    #             if sum2 + max_sum1 > max_sum12:
    #                 max_sum12 = sum2 + max_sum1
    #                 max_sum12_idx = (max_sum1_idx, i - 2 * k + 1)
    #             if sum3 + max_sum12 > max_sum123:
    #                 max_sum123 = sum3 + max_sum12
    #                 ans = [max_sum12_idx[0], max_sum12_idx[1], i - k + 1]
    #             sum1 -= nums[i - 3 * k + 1]
    #             sum2 -= nums[i - 2 * k + 1]
    #             sum3 -= nums[i - k + 1]
    #     return ans

    # ����������̬�滮
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        sum = [0] * (n + 1)
        for i in range(1, n + 1):
            sum[i] = nums[i - 1] + sum[i - 1]
        # dp[i][j] ��ʾǰ i ��Ԫ���У�j �������������
        dp = [[0] * 4 for _ in range(n + 2)]
        # �����������Ϊ����������������Ҫ�õ�ǰ��������������
        for i in range(n - k + 1, 0, -1):
            for j in range(1, 4):
                # �����ŷ����а��� num[i], ֻ���� [0, i - k] ��ѡ j - 1 ��������
                # �����ŷ����в����� num[i], dp[i][j] = dp[i - 1][j]
                dp[i][j] = max(dp[i + 1][j],
                               dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1])
        ans = [0] * 3
        i, j, idx = 1, 3, 0
        while j > 0:
            if dp[i + 1][j] > dp[i + k][j - 1] + sum[i + k - 1] - sum[i - 1]:
                i += 1
            else:
                ans[idx] = i - 1
                idx += 1
                i += k
                j -= 1
        return ans