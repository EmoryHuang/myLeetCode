'''
Descroption: LeetCode 859. 亲密字符串
Author: EmoryHuang
Date: 2021-06-08 20:22:00
解题思路:
字符串长度不相等, 直接返回false
字符串相等的时候, 只要有重复的元素就返回true
A, B字符串有不相等的两个地方, 需要查看它们交换后是否相等即可
'''


class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        if s == goal:
            cnt = set()
            for c in s:
                if c in cnt:  # 有重复元素
                    return True
                cnt.add(c)
            return False
        diff1 = []  # 记录不同字符
        diff2 = []
        cnt = 0  # 记录不同字符个数
        for i in range(len(s)):
            if s[i] != goal[i]:
                diff1.append(s[i])
                diff2.append(goal[i])
                cnt += 1
        # 不同字符为2，并且交换后相等
        if cnt == 2 and diff1[0] == diff2[1] and diff1[1] == diff2[0]:
            return True
        return False
