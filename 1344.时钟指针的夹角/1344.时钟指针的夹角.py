'''
Descroption: LeetCode 1344. ʱ��ָ��ļн�
Author: EmoryHuang
Date: 2021-07-25 14:09:43
Method:
����ʱ��ͷ����ߵĽǶȣ�ȡ��С���Ǹ�
'''


class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        # ʱ��һСʱ��30�ȣ�һ������ 30 / 60 = 0.5��
        harg = hour * 30 + minutes * 0.5
        # ����һ������ 360 / 60 = 6��
        marg = minutes * 6
        if abs(harg - marg) < 180:
            return abs(harg - marg)
        else:
            return 360 - abs(harg - marg)
