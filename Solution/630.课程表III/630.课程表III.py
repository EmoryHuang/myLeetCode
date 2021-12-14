'''
Descroption: LeetCode 630. 课程表 III
Author: EmoryHuang
Date: 2021-12-13 14:12:20
Method:
贪心
将课程按结束时间排序，使用优先队列记录当前课程时间
若如果当前上课总时间超过了当前课程的最后时间，则取出优先队列中的持续时间最长的课程
'''


class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        # 按课程截止时间排序
        courses.sort(key=lambda x: x[1])
        heap = []
        total = 0  # 记录课程总时间
        for dur, la in courses:
            total += dur
            heapq.heappush(heap, -dur)
            # 如果当前上课总时间超过了当前课程的最后时间
            if (total > la):
                total -= -heapq.heappop(heap)
        return len(heap)
