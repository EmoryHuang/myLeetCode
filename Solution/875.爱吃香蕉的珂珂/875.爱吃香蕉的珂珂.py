'''
Descroption: LeetCode 875. �����㽶������
Author: EmoryHuang
Date: 2021-07-21 20:01:15
����˼·:
���ַ�Ѱ�����п��ܵ��ٶȣ��жϵ�ǰ�ٶ��Ƿ�����Ҫ��
'''


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(k: int) -> bool:
            cnt = 0
            for pile in piles:
                cnt += math.ceil(pile / k)
            return cnt <= h

        if len(piles) == 1:
            return math.ceil(piles[0] / h)
        l, r = 1, max(piles)
        while l < r:
            mid = (l + r) >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l
