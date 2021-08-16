'''
Descroption: LeetCode 526. ����������
Author: EmoryHuang
Date: 2021-08-16 15:40:03
Method:
����һ��״̬ѹ�� + ����
ʹ�ö����ƴ���¼���ֵķ���״̬
���ݷ�����������ȱ�����ֱ��������������

��������״̬ѹ�� + dp
dp[i][state] ��ʾǰi����״̬Ϊstate�ķ�����
ö��i����,��i������״̬state�Լ���i������ֵk
״̬ת�Ʒ��̣�dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))]
���У�state & (~(1 << (k - 1))) �� state �еĵ� k λ�� 0��Ҳ����δѡȡ k ʱ��״̬
'''


class Solution:
    # ����һ��״̬ѹ�� + ����
    # def countArrangement(self, n: int) -> int:
    #     def dfs(i: int, vis: int) -> int:
    #         # ȫ������
    #         if vis == (1 << n) - 1:
    #             return 1
    #         ans = 0
    #         for ind in range(n):
    #             # �����ѷ��ʹ�����
    #             if (1 << ind) & vis:
    #                 continue
    #             # ���������������
    #             if i % (ind + 1) == 0 or (ind + 1) % i == 0:
    #                 vis ^= (1 << ind)
    #                 ans += dfs(i + 1, vis)
    #                 vis ^= (1 << ind)
    #         return ans

    #     return dfs(1, 0)

    # ��������״̬ѹ�� + dp
    def countArrangement(self, n: int) -> int:
        mask = 1 << n
        # dp[i][state] ��ʾǰi����״̬Ϊstate�ķ�����
        dp = [[0] * (mask) for _ in range(n + 1)]
        dp[0][0] = 1
        # ö������λ��
        for i in range(1, n + 1):
            # ö������״̬
            for state in range(mask):
                # ö��λ�� i ������ k
                for k in range(1, n + 1):
                    # λ�� k ������ 1
                    if (state >> (k - 1)) & 1 == 0:
                        continue
                    if i % k != 0 and k % i != 0:
                        continue
                    # state & (~(1 << (k - 1))) ��ʾ�� state �еĵ� k λ�� 0
                    # Ҳ����δѡȡ k ʱ��״̬
                    dp[i][state] += dp[i - 1][state & (~(1 << (k - 1)))]
        return dp[n][mask - 1]
