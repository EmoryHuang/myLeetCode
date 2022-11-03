'''
Descroption: LeetCode 1790. 仅执行一次字符串交换能否使两个字符串相等
Author: EmoryHuang
Date: 2022-10-11 09:09:25
Method:
计数
遍历s1, s2, 不相等的字符只可能有0个或2个
若不相等字符为2个，再判断字符是否相等
'''


class Solution:

    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        cnt = 0
        a = b = None
        for c1, c2 in zip(s1, s2):
            if c1 != c2:
                cnt += 1
                if cnt > 2 or (cnt == 2 and (a != c2 or b != c1)):
                    return False
                a, b = c1, c2
        return cnt != 1
