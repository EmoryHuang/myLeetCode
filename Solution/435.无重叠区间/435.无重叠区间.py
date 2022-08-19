'''
Descroption: LeetCode 435. ���ص�����
Author: EmoryHuang
Date: 2021-06-14 14:03:00
����˼·:
����һ��̰��˼��
�����Եĵڶ���ֵ��С��������
Ȼ��Ƚ� intervals[i][0] �� pre �Ĵ�С

����������̬�滮
dp[i]��ʾ�� intervals[i] ��β������ĳ���
״̬ת�Ʒ��̣�dp[i] = max(dp[i], dp[j] + 1)
'''


class Solution:
    # ����һ��̰��
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], x[0]))
        pre, ans = intervals[0][1], 0
        for i in range(1, len(intervals)):
            if intervals[i][0] < pre:
                ans += 1
                continue
            pre = intervals[i][1]
        return ans

    # ����������̬�滮
    # def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
    #     intervals.sort(key=lambda x: (x[0], x[1]))
    #     # dp[i]��ʾ�� intervals[i] ��β������ĳ���
    #     dp = [1] * len(intervals)
    #     for i in range(1, len(intervals)):
    #         for j in range(i):
    #             if intervals[i][0] >= intervals[j][1]:
    #                 dp[i] = max(dp[i], dp[j] + 1)
    #     return len(intervals) - max(dp)
