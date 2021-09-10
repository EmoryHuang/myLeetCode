'''
Descroption: LeetCode 539. 最小时间差
Author: EmoryHuang
Date: 2021-08-20 15:43:45
Method:
将时间转化为分钟，然后排序寻找最小时间差
其中，比较第一个数和最后一个数时，要加上 24 * 60
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
