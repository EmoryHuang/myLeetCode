'''
Descroption: LeetCode 1021. ɾ������������
Author: EmoryHuang
Date: 2021-09-14 16:36:05
Method:
ջ����ջ�ǿ�ʱ�����ż��� ans
���� ( / ) ʱ��ջ/��ջ
'''


class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        stack = []
        ans = ''
        for c in s:
            if c == ')':
                stack.pop()
            if stack:
                ans += c
            if c == '(':
                stack.append('(')
        return ans