'''
Descroption: LeetCode 168. Excel ��������
Author: EmoryHuang
Date: 2021-06-29 17:02:00
����˼·:
������ת��Ϊ�ַ�������ȡ�࣬ͨ�� string ƴ��
'''


class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        ans = ''
        while columnNumber:
            columnNumber -= 1
            ans = chr(columnNumber % 26 + 65) + ans
            columnNumber //= 26
        return ans
