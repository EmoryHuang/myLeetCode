'''
Descroption: LeetCode 313. ��������
Author: EmoryHuang
Date: 2021-08-09 13:42:25
Method:
����һ����С��
ÿ��ȡ���Ѷ�Ԫ�� x���� x �Ƕ�����С�ĳ�������
�������� primes ���������� p��px Ҳ�ǳ�����������˽��˻������
�ظ�����n�μ��ǵ�n����������
����������̬�滮
dp[i] ��ʾ��i����������
ʹ��m��ָ��ֱ�ָ��dp[i]��primes[i]��������������������
'''


class Solution:
    # ����һ����С��
    # def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
    #     heap = [1]
    #     vis = {1}
    #     for i in range(n):
    #         ugly = heapq.heappop(heap)
    #         for prime in primes:
    #             next = ugly * prime
    #             if next not in vis:
    #                 vis.add(next)
    #                 heapq.heappush(heap, next)
    #     return ugly

    # ����������̬�滮
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        m = len(primes)
        # dp[i] ��ʾ��i����������
        dp = [0] * (n + 1)
        dp[1] = 1
        # p[j] ��ʾ j ��ָ��
        p = [1] * m
        for i in range(2, n + 1):
            minn = min(primes[j] * dp[p[j]] for j in range(m))
            dp[i] = minn
            for j in range(m):
                if primes[j] * dp[p[j]] == minn:
                    p[j] += 1
        return dp[n]
