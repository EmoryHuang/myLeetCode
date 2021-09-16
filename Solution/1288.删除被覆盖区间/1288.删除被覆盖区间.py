'''
Descroption: LeetCode 1288. ɾ������������
Author: EmoryHuang
Date: 2021-09-15 18:45:08
Method:
����
�� intervals ��һ������С���󣬵ڶ������Ӵ�С
Ȼ����� intervals �� pre_l <= l and pre_r >= r ����Ϊ�Ǹ���
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
