'''
Descroption: LeetCode 2180. 统计各位数字之和为偶数的整数个数
Author: EmoryHuang
Date: 2023-01-06 09:02:50
Method:
简单题，暴力遍历所有正整数
'''


class Solution:
    def countEven(self, num: int) -> int:
        ans = 0
        for x in range(1, num + 1):
            cur = 0
            while x:
                cur += x % 10
                x //= 10
            if cur % 2 == 0:
                ans += 1
        return ans