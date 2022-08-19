'''
Descroption: LeetCode 731. 我的日程安排表 II
Author: EmoryHuang
Date: 2021-08-11 20:14:19
Method:
暴力遍历，检查当前每个日程安排是否与新日程安排冲突
首先判断是否已经重复，若再次重复，则返回 false
若之前未重复，则将最小的重叠交集加入
'''


class MyCalendarTwo:
    def __init__(self):
        self.cal = []
        self.over = []

    def book(self, start: int, end: int) -> bool:
        # 首先判断是否已经重复
        for l, r in self.over:
            if l < end and r > start:
                return False
        # 若之前未重复
        for l, r in self.cal:
            if l < end and r > start:
                # 将最小的重叠交集加入
                self.over.append([max(start, l), min(end, r)])
        self.cal.append([start, end])
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)