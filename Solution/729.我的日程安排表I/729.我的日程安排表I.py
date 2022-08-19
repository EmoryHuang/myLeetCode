'''
Descroption: LeetCode 729. �ҵ��ճ̰��ű� I
Author: EmoryHuang
Date: 2021-08-11 20:06:07
Method:
������������鵱ǰÿ���ճ̰����Ƿ������ճ̰��ų�ͻ
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