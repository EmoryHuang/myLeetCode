'''
Descroption: LeetCode 1844. 将所有数字用字符替换
Author: EmoryHuang
Date: 2021-07-15 19:18:33
解题思路:
简单题，遍历字符串，若下标为奇数则对其进行替换
'''


class Solution:
    def replaceDigits(self, s: str) -> str:
        arr = list(s)
        for i in range(len(s)):
            if i % 2 != 0:
                arr[i] = chr(ord(arr[i - 1]) + int(arr[i]))
        return ''.join(arr)
