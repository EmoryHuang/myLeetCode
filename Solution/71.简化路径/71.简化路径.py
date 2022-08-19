'''
Descroption: LeetCode 71. ��·��
Author: EmoryHuang
Date: 2022-01-06 13:42:17
Method:
ջ��������Ŀ¼������ջ
������ '', '.' ������
���� '..' ʱ����ջ�ǿգ���Ҫ��Ŀ¼�л�����һ�����򵯳�ջ��Ԫ��
'''


class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        for p in path.split('/'):
            if p not in ['', '.', '..']:
                stack.append(p)
            elif p == '..' and stack:
                stack.pop()
        return '/' + '/'.join(stack)