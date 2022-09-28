'''
Descroption: LeetCode 436. 寻找右区间
Author: EmoryHuang
Date: 2022-05-20 08:56:10
Method:
二分查找
由于每个间隔的起点都不相同，因此将起点进行存储同时记录原始位置存储在 idx，按照左边界排序
枚举右端点，使用二分查找 idx 中大于等于 intervals[i][1] 的最小值
'''


class Solution:
    def findRightInterval(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        # 由于每个间隔的起点都不相同，因此将起点进行存储并记录原始位置
        idx = [(interval[0], i) for i, interval in enumerate(intervals)]
        # 按照左边界排序
        idx.sort()

        ans = [-1] * n
        for i in range(n):
            # 枚举右端点，使用二分查找 idx 中大于等于 intervals[i][1] 的最小值
            j = bisect.bisect_left(idx, (intervals[i][1], 0))
            if j < n:
                ans[i] = idx[j][1]
        return ans