'''
Descroption: LeetCode 1995. ͳ��������Ԫ��
Author: EmoryHuang
Date: 2021-12-29 09:12:30
Method:
����һ: ����
���⣬���� N �ķ�Χ��С������ֱ�ӱ�������

# ������: ��������
���� dp[i][j][k] Ϊ����ǰ i ����Ʒ���ճ���ֵǡ�� j��ʹ�ø���ǡ��Ϊ k �ķ�����
״̬ת�Ʒ���
�����������Ʒ nums[i-1], ��ô f[i][j][k] = f[i - 1][j][k]
���������Ʒ nums[i-1], ��ô f[i][j][k] = f[i - 1][j - nums[i - 1]][k - 1]

�ռ��Ż�: ͨ������������Ϳռ临�Ӷ�
'''


class Solution:
    # ����һ: ����
    # def countQuadruplets(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     ans = 0
    #     for a in range(n):
    #         for b in range(a + 1, n):
    #             for c in range(b + 1, n):
    #                 for d in range(c + 1, n):
    #                     if nums[a] + nums[b] + nums[c] == nums[d]:
    #                         ans += 1
    #     return ans

    # ������: ��������
    # def countQuadruplets(self, nums: List[int]) -> int:
    #     n = len(nums)
    #     # dp[i][j][k] Ϊ����ǰ i ����Ʒ���ճ���ֵǡ�� j��ʹ�ø���ǡ��Ϊ k �ķ�����
    #     dp = [[[0] * 4 for _ in range(101)] for _ in range(n + 1)]
    #     dp[0][0][0] = 1
    #     for i in range(1, n + 1):
    #         for j in range(101):
    #             for k in range(4):
    #                 dp[i][j][k] += dp[i - 1][j][k]
    #                 # ������ܷ��µ� i ����Ʒ
    #                 if j - nums[i - 1] >= 0 and k - 1 >= 0:
    #                     dp[i][j][k] += dp[i - 1][j - nums[i - 1]][k - 1]
    #     ans = 0
    #     for i in range(3, n + 1):
    #         ans += dp[i][nums[i - 1]][3]
    #     return ans

    # ������: ��������(�ռ��Ż�)
    def countQuadruplets(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        # dp[i][j][k] Ϊ����ǰ i ����Ʒ���ճ���ֵǡ�� j��ʹ�ø���ǡ��Ϊ k �ķ�����
        dp = [[0] * 4 for _ in range(101)]
        dp[0][0] = 1
        for i in range(1, n + 1):
            ans += dp[nums[i - 1]][3]
            # �������
            for j in range(100, -1, -1):
                for k in range(4):
                    if j - nums[i - 1] >= 0 and k - 1 >= 0:
                        dp[j][k] += dp[j - nums[i - 1]][k - 1]
        return ans
