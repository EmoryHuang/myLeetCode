'''
Descroption: LeetCode 1323. 6 �� 9 ��ɵ��������
Author: EmoryHuang
Date: 2021-09-17 18:57:20
Method:
����ֻ��4λ���֣����ֻ��Ҫ�Ӹ�λ����λ���� 6 ��� 9
'''


class Solution:
    def maximum69Number(self, num: int) -> int:
        if num // 1000 == 6:
            return num + 3000
        if (num // 100) % 10 == 6:
            return num + 300
        if (num // 10) % 10 == 6:
            return num + 30
        if num % 10 == 6:
            return num + 3
        return num