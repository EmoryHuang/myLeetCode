'''
Descroption: LeetCode 71. 简化路径
Author: EmoryHuang
Date: 2022-01-06 13:42:17
Method:
栈，若遇到目录名则入栈
若遇到 '', '.' 则跳过
遇到 '..' 时，若栈非空，需要将目录切换到上一级，则弹出栈顶元素
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