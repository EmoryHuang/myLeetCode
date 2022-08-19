'''
Descroption: LeetCode 394. �ַ�������
Author: EmoryHuang
Date: 2021-08-24 16:12:53
Method:
ʹ��ջ��¼ '[' ǰ�������ǰ��Ľ���Լ��ظ�����
������� '[' ��ǰ��Ľ���Լ��ظ�������ջ
������� ']' ������ظ�
'''


class Solution:
    def decodeString(self, s: str) -> str:
        stack = []  # (ans, num) ǰ��Ľ���Լ��ظ�����
        num = 0
        ans = ''
        for c in s:
            if c.isdigit():
                num = num * 10 + int(c)
            elif c == '[':
                # ������� '[' ��ǰ��Ľ���Լ��ظ�������ջ
                stack.append((ans, num))
                ans, num = '', 0
            elif c == ']':
                # ������� ']' ������ظ�
                top = stack.pop()
                ans = top[0] + ans * top[1]
            else:
                ans += c
        return ans
