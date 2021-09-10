'''
Descroption: LeetCode 342. 4的幂
Author: EmoryHuang
Date: 2021-05-31 19:15:22
解题思路:  
方法一：循环

方法二：取模
通过 n 除以 3 的余数是否为 1 来判断 n 是否是 4 的幂
'''


# 方法一：循环
# class Solution:
#     def isPowerOfFour(self, n: int) -> bool:
#         if n == 1:
#             return True
#         if n <= 0 or n % 2 == 1:
#             return False
#         while n % 4 == 0:
#             n /= 4
#         return n == 1


# 方法二：取模
class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        if n == 1:
            return True
        if n <= 0 or n % 2 == 1:
            return False
        return n > 0 and (n & (n-1)) == 0 and n % 3 == 1