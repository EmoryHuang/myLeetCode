'''
Descroption: LeetCode 1422. �ָ��ַ��������÷�
Author: EmoryHuang
Date: 2021-08-08 14:11:57
Method:
ͳ��0��1������
'''


class Solution:
    def maxScore(self, s: str) -> int:
        zero, one, ans = 0, s.count('1'), 0
        for i in range(len(s) - 1):
            if s[i] == '0':
                zero += 1
            else:
                one -= 1
            ans = max(ans, one + zero)
        return ans
