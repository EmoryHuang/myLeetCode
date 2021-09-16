'''
Descroption: LeetCode 1288. 删除被覆盖区间
Author: EmoryHuang
Date: 2021-09-15 18:45:08
Method:
排序
按 intervals 第一个数从小到大，第二个数从大到小
然后遍历 intervals 若 pre_l <= l and pre_r >= r 则认为是覆盖
'''


class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans = [intervals[0]]
        for l, r in intervals:
            pre_l, pre_r = ans[-1]
            if pre_l <= l and pre_r >= r:
                continue
            ans.append([l, r])
        return len(ans)
