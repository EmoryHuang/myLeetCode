'''
Descroption: LeetCode 168. Excel 表列名称
Author: EmoryHuang
Date: 2021-06-29 17:02:00
解题思路:
将数字转化为字符，整除取余，通过 string 拼接
'''


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ''
        while columnNumber:
            columnNumber -= 1
            ans = chr(columnNumber % 26 + 65) + ans
            columnNumber //= 26
        return ans
