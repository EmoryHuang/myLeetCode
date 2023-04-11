'''
Descroption: LeetCode 1017. 负二进制转换
Author: EmoryHuang
Date: 2023-04-06 09:41:20
Method:
模拟
'''


class Solution:
    def baseNeg2(self, n: int) -> str:
        if n == 0 or n == 1:
            return str(n)
        ans = []
        while n:
            remainer = n & 1
            ans.append(str(remainer))
            n -= remainer
            n //= -2
        return ''.join(ans[::-1])