'''
Descroption: LeetCode 796. ��ת�ַ���
Author: EmoryHuang
Date: 2021-06-26 14:17:00
����˼·:
���⣬�� s + s ���ж��Ƿ�����Ӵ� goal
'''


class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        return len(s) == len(goal) and goal in (s + s)
