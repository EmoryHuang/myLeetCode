'''
Descroption: LeetCode 650. 只有两个键的键盘
Author: EmoryHuang
Date: 2021-09-19 14:26:38
Method:
数学/动态规划
如果 n 是一个质数，那么次数就是它本身
如果 n 是一个合数，对数字进行因数分解
'''


class Solution:
    def minSteps(self, n: int) -> int:
        ans = 0
        for i in range(2, n + 1):
            while n % i == 0:
                ans += i
                n //= i
        return ans