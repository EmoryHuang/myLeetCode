'''
Descroption: LeetCode 1952. ������
Author: EmoryHuang
Date: 2021-08-23 19:09:24
Method:
���⣬�����жϳ�������
'''


class Solution:
    def isThree(self, n: int) -> bool:
        ans = 0
        for i in range(1, ceil(sqrt(n)) + 1):
            if n % i == 0:
                ans += 2
            if i == sqrt(n):
                ans -= 1
        return ans == 3

