'''
Descroption: LeetCode 1784. ���������ַ����ֶ�
Author: EmoryHuang
Date: 2021-08-05 20:00:03
Method:
���⣬��¼���ֱ仯�Ĵ���
'''


class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        cnt = 0
        for i in range(1, len(s)):
            if s[i] != s[i - 1]:
                cnt += 1
        return cnt <= 1
