'''
Descroption: LeetCode 65. ��Ч����
Author: EmoryHuang
Date: 2021-06-17 13:13:00
����˼·:
ģ�⣬�������ۣ��ж��Ƿ��������
'''


class Solution:
    def isNumber(self, s: str) -> bool:
        hasE, hasNum, isFloat = False, False, False
        for i, c in enumerate(s):
            # ����λֻ������λ��E�ĺ�һλ
            if (c == '+' or c == '-') and (i == 0 or s[i-1] == 'E' or s[i-1] == 'e'):
                pass
            # ֻ����һ��E, ǰ�����������, ����Ҳ����������
            elif (c == 'E' or c == 'e') and not hasE and hasNum:
                hasE = True
                hasNum = False
            # ֻ����һ��С����, ������E�ĺ���
            elif c == '.' and not isFloat and not hasE:
                isFloat = True
            elif c.isdigit():
                hasNum = True
            else:
                return False
        return hasNum

    # ������ʽ
    # def isNumber(self, s: str) -> bool:
    #     return bool(re.fullmatch(r'[+-]?(\d+)?\.?(?(1)\d*|\d+)([eE][+-]?\d+)?', s))
