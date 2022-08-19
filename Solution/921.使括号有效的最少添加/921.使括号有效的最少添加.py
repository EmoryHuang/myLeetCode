'''
Descroption: LeetCode 921. ʹ������Ч���������
Author: EmoryHuang
Date: 2021-07-23 20:31:15
����˼·:
ʹ��ջ�洢
�����ַ����������� '('������ջ��
������ ')'������ʱջ�Ƿ�Ϊ�գ���˵��û��ƥ��� '('��cnt += 1�������ջ
'''


class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        stack = []
        cnt = 0
        for c in s:
            if c == '(':
                stack.append(c)
            else:
                if not stack:
                    cnt += 1
                else:
                    stack.pop()
        return cnt + len(stack)
