'''
Descroption: LeetCode 1507. 转变日期格式
Author: EmoryHuang
Date: 2021-07-30 19:51:59
Method:
简单题
'''


class Solution:
    def reformatDate(self, date: str) -> str:
        mons = {
            "Jan": '01',
            "Feb": '02',
            "Mar": '03',
            "Apr": '04',
            "May": '05',
            "Jun": '06',
            "Jul": '07',
            "Aug": '08',
            "Sep": '09',
            "Oct": '10',
            "Nov": '11',
            "Dec": '12'
        }
        ls = date.split()
        year = ls[-1]
        day = ''
        for c in ls[0]:
            if c.isdigit():
                day += c
        if len(day) == 1:
            day = '0' + day
        return year + '-' + mons[ls[1]] + '-' + day
