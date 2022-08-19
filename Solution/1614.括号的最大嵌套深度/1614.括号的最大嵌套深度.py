'''
Descroption: LeetCode 1614. ���ŵ����Ƕ�����
Author: EmoryHuang
Date: 2021-10-20 08:41:44
Method:
���⣬ʹ��ջ��¼���ŵ����Ƕ�����
'''


class Solution:
    def maxDepth(self, s: str) -> int:
        stack = deque()
        ans = 0
        for c in s:
            if c == '(':
                stack.append(c)
                ans = max(ans, len(stack))
            elif c == ')':
                stack.pop()
        return ans