'''
Descroption: LeetCode 731. �ҵ��ճ̰��ű� II
Author: EmoryHuang
Date: 2021-08-11 20:14:19
Method:
������������鵱ǰÿ���ճ̰����Ƿ������ճ̰��ų�ͻ
�����ж��Ƿ��Ѿ��ظ������ٴ��ظ����򷵻� false
��֮ǰδ�ظ�������С���ص���������
'''


class MyCalendarTwo:
    def __init__(self):
        self.cal = []
        self.over = []

    def book(self, start: int, end: int) -> bool:
        # �����ж��Ƿ��Ѿ��ظ�
        for l, r in self.over:
            if l < end and r > start:
                return False
        # ��֮ǰδ�ظ�
        for l, r in self.cal:
            if l < end and r > start:
                # ����С���ص���������
                self.over.append([max(start, l), min(end, r)])
        self.cal.append([start, end])
        return True


# Your MyCalendarTwo object will be instantiated and called as such:
# obj = MyCalendarTwo()
# param_1 = obj.book(start,end)