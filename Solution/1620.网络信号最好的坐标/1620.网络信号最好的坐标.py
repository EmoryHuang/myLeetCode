'''
Descroption: LeetCode 1620. �����ź���õ�����
Author: EmoryHuang
Date: 2021-11-05 20:07:33
Method:
�������е㣬�ҵ������ź���õ�����
'''


class Solution:
    def bestCoordinate(self, towers: List[List[int]], radius: int) -> List[int]:
        ans = [0, 0]
        maxq = 0
        # �������е�
        for i in range(51):
            for j in range(51):
                cur = 0
                for x, y, q in towers:
                    d = sqrt((x - i)**2 + (y - j)**2)
                    if d <= radius:
                        cur += int(q / (1 + d))
                if cur > maxq:
                    maxq = cur
                    ans = [i, j]
        return ans