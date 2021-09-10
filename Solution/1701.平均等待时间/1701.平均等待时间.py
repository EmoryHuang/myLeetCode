'''
Descroption: LeetCode 1701. ƽ���ȴ�ʱ��
Author: EmoryHuang
Date: 2021-07-28 20:04:37
Method:
ά����ǰʱ�� cur
�� cur < arrival������� cur = arrival
ÿ���˿���Ҫ�ȴ���ʱ��Ϊ time + (cur - arrival)
'''


class Solution:
    def averageWaitingTime(self, customers: List[List[int]]) -> float:
        n = len(customers)
        cur, ans = 0, 0
        for arrival, time in customers:
            if cur < arrival:
                cur = arrival
            ans += time + (cur - arrival)
            cur += time
        return ans / n
