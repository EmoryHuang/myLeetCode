'''
Descroption: LeetCode 1342. 将数字变成 0 的操作次数
Author: EmoryHuang
Date: 2021-07-25 14:29:46
Method:
简单题，按照公式计算
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
