'''
Descroption: LeetCode 1994. ���Ӽ�����Ŀ
Author: EmoryHuang
Date: 2022-02-22 16:03:24
Method:
��̬�滮
����ʹ�õ��������ޣ���˿���ʹ��1��������λ��¼ÿ�����ֵ�ʹ�����
dp[mask] ��ʾ����ʹ�����Ϊ mask ʱ�ķ�������
���ڷ���ͨ���±��������������Ҫͳ�� nums ��ÿ�����ֳ��ֵ�Ƶ��
���� nums �е�ÿ�����֣��ж����������Ƿ��������ͬ��������subset ��¼����ʹ�����
����ö��״̬����֤��ǰѡ���״̬��ǰһ��״̬�����ͻ�������������ۼ�
'''


class Solution:
    def numberOfGoodSubsets(self, nums: List[int]) -> int:
        primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29]
        mod = 10**9 + 7
        cnts = Counter(nums)

        # dp[mask] ��ʾ����ʹ�����Ϊ mask ʱ�ķ�������
        dp = [0] * (1 << len(primes))
        dp[0] = 1 << cnts[1] % mod
        for num, freq in cnts.items():
            if num == 1:
                continue
            # �ж�ÿ�����������Ƿ��������ͬ������
            # subset ��¼����ʹ�����
            flag, subset = True, 0
            for i, p in enumerate(primes):
                if num % (p**2) == 0:
                    flag = False
                    break
                if num % p == 0:
                    subset |= 1 << i
            if not flag:
                continue

            # ����ö��״̬
            # ��֤��ǰѡ���״̬��ǰһ��״̬�����ͻ�������������ۼ�
            for mask in range((1 << len(primes)) - 1, 0, -1):
                if (mask & subset) == subset:
                    dp[mask] = (dp[mask] + dp[mask ^ subset] * freq) % mod
        ans = sum(dp[1:]) % mod
        return ans
