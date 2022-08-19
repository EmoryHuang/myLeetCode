'''
Descroption: LeetCode 1154. һ���еĵڼ���
Author: EmoryHuang
Date: 2021-12-21 08:42:47
Method:
���⣬�ж��Ƿ������꣬Ȼ�����������·�����������
'''


class Solution:
    def dayOfYear(self, date: str) -> int:
        year, month, day = date.split('-')
        month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if int(year) % 4 == 0 and int(year) % 100 != 0 or int(year) % 400 == 0:
            month_days[1] = 29
        return sum(month_days[:int(month) - 1]) + int(day)
