'''
Descroption: LeetCode 1154. 一年中的第几天
Author: EmoryHuang
Date: 2021-12-21 08:42:47
Method:
简单题，判断是否是闰年，然后根据闰年和月份来计算天数
'''


class Solution:
    def dayOfYear(self, date: str) -> int:
        year, month, day = date.split('-')
        month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
        if int(year) % 4 == 0 and int(year) % 100 != 0 or int(year) % 400 == 0:
            month_days[1] = 29
        return sum(month_days[:int(month) - 1]) + int(day)
