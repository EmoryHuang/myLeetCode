'''
Descroption: LeetCode 1342. �����ֱ�� 0 �Ĳ�������
Author: EmoryHuang
Date: 2021-07-25 14:29:46
Method:
���⣬���չ�ʽ����
'''


class Solution:
    def numberOfSteps(self, num: int) -> int:
        cnt = 0
        while num:
            if num % 2 == 0:
                num //= 2
            else:
                num -= 1
            cnt += 1
        return cnt
