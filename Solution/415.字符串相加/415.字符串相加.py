'''
Descroption: LeetCode 415. 字符串相加
Author: EmoryHuang
Date: 2021-05-31 19:36:22
解题思路:  
大数加法, 维护一个进位变量
'''


class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        i, j, cur = len(num1)-1, len(num2)-1, 0
        ans = ""
        while i >= 0 or j >= 0 or cur != 0:
            if i >= 0:
                cur += int(num1[i])
            if j >= 0:
                cur += int(num2[j])
            ans = str(cur % 10) + ans
            cur //= 10
            i, j = i-1, j-1
        return ans
