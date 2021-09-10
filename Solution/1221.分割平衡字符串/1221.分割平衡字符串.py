'''
Descroption: LeetCode 1221. �ָ�ƽ���ַ���
Author: EmoryHuang
Date: 2021-08-23 19:19:07
Method:
̰�ģ�����L��R�ĸ�����������������¼����������
'''


class Solution:
    def balancedStringSplit(self, s: str) -> int:
        l, r = 0, 0
        ans = 0
        for c in s:
            if c == 'L': l += 1
            if c == 'R': r += 1
            if l == r:
                ans += 1
                l, r = 0, 0
        return ans