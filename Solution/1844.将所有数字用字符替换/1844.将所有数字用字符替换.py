'''
Descroption: LeetCode 1844. �������������ַ��滻
Author: EmoryHuang
Date: 2021-07-15 19:18:33
����˼·:
���⣬�����ַ��������±�Ϊ�������������滻
'''


class Solution:
    def replaceDigits(self, s: str) -> str:
        arr = list(s)
        for i in range(len(s)):
            if i % 2 != 0:
                arr[i] = chr(ord(arr[i - 1]) + int(arr[i]))
        return ''.join(arr)
