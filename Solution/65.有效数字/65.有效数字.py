'''
Descroption: LeetCode 65. 有效数字
Author: EmoryHuang
Date: 2021-06-17 13:13:00
解题思路:
模拟，分类讨论，判断是否符合条件
'''


class Solution:
    def isNumber(self, s: str) -> bool:
        hasE, hasNum, isFloat = False, False, False
        for i, c in enumerate(s):
            # 符号位只能在首位或E的后一位
            if (c == '+' or c == '-') and (i == 0 or s[i-1] == 'E' or s[i-1] == 'e'):
                pass
            # 只存在一个E, 前面必须有数字, 后面也必须有数字
            elif (c == 'E' or c == 'e') and not hasE and hasNum:
                hasE = True
                hasNum = False
            # 只存在一个小数点, 不能在E的后面
            elif c == '.' and not isFloat and not hasE:
                isFloat = True
            elif c.isdigit():
                hasNum = True
            else:
                return False
        return hasNum

    # 正则表达式
    # def isNumber(self, s: str) -> bool:
    #     return bool(re.fullmatch(r'[+-]?(\d+)?\.?(?(1)\d*|\d+)([eE][+-]?\d+)?', s))
