'''
Descroption: LeetCode 1870. ׼ʱ������г���Сʱ��
Author: EmoryHuang
Date: 2021-07-22 19:21:39
����˼·:
���ַ�������������г���Сʱ��
����ʱ��ʱ���������һ��ʱ����������ȡ��
�����ٶȿ�����10^7
'''


class Solution:
    def minSpeedOnTime(self, dist: List[int], hour: float) -> int:
        def check(speed: int) -> bool:
            cnt = 0
            for d in dist[:-1]:
                cnt += math.ceil(d / speed)
            cnt += dist[-1] / speed
            return cnt <= hour

        l, r = 1, 10**7 + 1
        while l < r:
            mid = l + r >> 1
            if check(mid):
                r = mid
            else:
                l = mid + 1
        return l if l <= 10**7 else -1
