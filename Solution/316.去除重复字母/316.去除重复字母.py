'''
Descroption: LeetCode 316. 去除重复字母
Author: EmoryHuang
Date: 2021-08-03 13:47:18
Method:
遍历字符，维护一个单调栈，
若在该字符后面还有这个字符，则弹出，否则入栈
'''

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        hash = Counter(s)
        stack = []
        for c in s:
            if c not in stack:  # 如果当前字符不在栈中
                # 维护一个单调栈
                # 若在该字符后面还有这个字符，则弹出
                while stack and stack[-1] > c and hash[stack[-1]] > 0:
                    stack.pop()
                stack.append(c)
            hash[c] -= 1
        return ''.join(stack)