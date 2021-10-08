'''
Descroption: LeetCode 2008. ���⳵�����ӯ��
Author: EmoryHuang
Date: 2021-10-08 20:25:37
Method:
����һ����̬�滮
dp[i] ��ʾ�� i ��β��λ���ܵõ����������
�����ؿͣ����� dp[i] = dp[i - 1]
���ؿͣ���ѡ��ǰλ���ܻ�õ�������� dp[i] = max(dp[i], dp[start] + profit)

����������̬�滮 + ����
״̬ת�Ʒ���: dp[i] = max(dp[i - 1], dp[r] + end - start + tip)
ʹ�ö��ֲ��ң�Ѱ�Ҿ��뵱ǰ�յ���������λ��
'''


class Solution:
    # ����һ����̬�滮
    # def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
    #     # dp[i] ��ʾ�� i ��β��λ���ܵõ����������
    #     dp = [0] * (n + 1)
    #     d = defaultdict(list)
    #     for start, end, tip in rides:
    #         d[end].append([start, end - start + tip])
    #     for i in range(1, n + 1):
    #         # ���ؿ�
    #         dp[i] = dp[i - 1]
    #         for start, w in d[i]:
    #             dp[i] = max(dp[i], dp[start] + w)
    #     return dp[n]

    # ����������̬�滮 + ����
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        m = len(rides)
        # ���յ�����
        rides.sort(key=lambda x: x[1])
        dp = [0] * (m + 1)
        for i in range(1, m + 1):
            start, end, tip = rides[i - 1]
            # ���ַ�Ѱ�Ҿ��뵱ǰ�յ���������λ��
            l, r = 0, i - 1
            while l < r:
                mid = l + r + 1 >> 1
                if rides[mid - 1][1] <= start:
                    l = mid
                else:
                    r = mid - 1
            dp[i] = max(dp[i - 1], dp[r] + end - start + tip)
        return dp[m]
