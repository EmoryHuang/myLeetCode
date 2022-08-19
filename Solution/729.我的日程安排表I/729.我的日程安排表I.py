'''
Descroption: LeetCode 729. 我的日程安排表 I
Author: EmoryHuang
Date: 2021-08-11 20:06:07
Method:
暴力遍历，检查当前每个日程安排是否与新日程安排冲突
'''


class MyCalendar:
    def __init__(self):
        self.cal = []

    def book(self, start: int, end: int) -> bool:
        for l, r in self.cal:
            if l < end and r > start:
                return False
        self.cal.append([start, end])
        return True


# Your MyCalendar object will be instantiated and called as such:
# obj = MyCalendar()
# param_1 = obj.book(start,end)