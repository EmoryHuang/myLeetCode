'''
Descroption: LeetCode 1052. ������������ϰ�
Author: EmoryHuang
Date: 2021-08-06 15:57:33
Method:
��������
�����ų���������ʱ�Ĺ˿ͣ�ֻ��������ʱ�Ĺ˿�
������СΪ minutes �Ļ������ڣ����㲻����ʱ�����˿���Ŀ
'''


class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int],
                     minutes: int) -> int:
        n, ans = len(customers), 0
        # ���㲻����ʱ�Ĺ˿�����
        for i, customer in enumerate(customers):
            if grumpy[i] == 0:
                ans += customer
                customers[i] = 0
        # ��������
        sumn = sum(customers[:minutes])
        r, maxn = minutes, sumn
        while r < n:
            sumn += customers[r]
            sumn -= customers[r - minutes]
            maxn = max(maxn, sumn)
            r += 1
        return ans + maxn
