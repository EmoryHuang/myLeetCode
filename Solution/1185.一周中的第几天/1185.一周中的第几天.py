'''
Descroption: LeetCode 1185. һ���еĵڼ���
Author: EmoryHuang
Date: 2022-01-03 19:03:48
Method:
����һ: ����
���˵��⻹�����ò��չ�ʽ����

������: ģ��
'''


class Solution:
    # ����һ: ����
    # def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
    #     return datetime.date(year, month, day).strftime('%A')

    # ������: ģ��
    def dayOfTheWeek(self, day: int, month: int, year: int) -> str:
        weeks = [
            "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
        ]
        days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        ans = 4
        for i in range(1971, year):
            flag = (i % 4 == 0 and i % 100 != 0) or i % 400 == 0
            ans += 366 if flag else 365
        for i in range(1, month):
            ans += days[i - 1]
            if i == 2 and ((year % 4 == 0 and year % 100 != 0) or year % 400 == 0):
                ans += 1
        ans += day
        return weeks[ans % 7]