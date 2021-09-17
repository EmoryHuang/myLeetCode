'''
Descroption: LeetCode 1323. 6 和 9 组成的最大数字
Author: EmoryHuang
Date: 2021-09-17 18:57:20
Method:
由于只有4位数字，因此只需要从高位到低位，把 6 变成 9
'''


class Solution:
    def maximum69Number(self, num: int) -> int:
        if num // 1000 == 6:
            return num + 3000
        if (num // 100) % 10 == 6:
            return num + 300
        if (num // 10) % 10 == 6:
            return num + 30
        if num % 10 == 6:
            return num + 3
        return num