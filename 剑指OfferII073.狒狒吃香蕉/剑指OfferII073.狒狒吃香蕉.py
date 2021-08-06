'''
Descroption: ��ָ Offer II 073. �������㽶
Author: EmoryHuang
Date: 2021-08-06 18:32:18
Method:
���ַ�Ѱ�����п��ܵ��ٶȣ��жϵ�ǰ�ٶ��Ƿ�����Ҫ��
'''


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        def check(s: int) -> bool:
            cnt = 0
            for pile in piles:
                cnt += math.ceil(pile / s)
            return cnt <= h

        if len(piles) == 1:
            return math.ceil(piles[0] / h)
        l, r = 1, max(piles)
        while l < r:
            mid = l + (r - l) // 2
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l
