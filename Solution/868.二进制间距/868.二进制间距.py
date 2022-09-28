'''
Descroption: LeetCode 868. 二进制间距
Author: EmoryHuang
Date: 2022-04-24 08:43:19
Method:
位运算，记录二进制中两个1之间的最大距离
'''


class Solution:
    def binaryGap(self, n: int) -> int:
        cnt, ans = -float('inf'), 0
        while n:
            if n & 1:
                ans = max(ans, cnt)
                cnt = 1
            else:
                cnt += 1
            n >>= 1
        return ans
