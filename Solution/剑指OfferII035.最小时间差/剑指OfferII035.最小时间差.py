'''
Descroption: LeetCode 539. ��Сʱ���
Author: EmoryHuang
Date: 2021-08-20 15:43:45
Method:
��ʱ��ת��Ϊ���ӣ�Ȼ������Ѱ����Сʱ���
���У��Ƚϵ�һ���������һ����ʱ��Ҫ���� 24 * 60
'''


class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        mins = []
        for time in timePoints:
            h, m = time.split(':')
            mins.append(60 * int(h) + int(m))
        mins.sort()
        n = len(mins)
        ans = float('inf')
        for i in range(n - 1):
            ans = min(ans, mins[i + 1] - mins[i])
        return min(ans, 24 * 60 + mins[0] - mins[n - 1])
