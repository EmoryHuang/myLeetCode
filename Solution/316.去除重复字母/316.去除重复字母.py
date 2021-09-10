'''
Descroption: LeetCode 316. ȥ���ظ���ĸ
Author: EmoryHuang
Date: 2021-08-03 13:47:18
Method:
�����ַ���ά��һ������ջ��
���ڸ��ַ����滹������ַ����򵯳���������ջ
'''

class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        hash = Counter(s)
        stack = []
        for c in s:
            if c not in stack:  # �����ǰ�ַ�����ջ��
                # ά��һ������ջ
                # ���ڸ��ַ����滹������ַ����򵯳�
                while stack and stack[-1] > c and hash[stack[-1]] > 0:
                    stack.pop()
                stack.append(c)
            hash[c] -= 1
        return ''.join(stack)