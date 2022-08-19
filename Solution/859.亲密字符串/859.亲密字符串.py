'''
Descroption: LeetCode 859. �����ַ���
Author: EmoryHuang
Date: 2021-06-08 20:22:00
����˼·:
�ַ������Ȳ����, ֱ�ӷ���false
�ַ�����ȵ�ʱ��, ֻҪ���ظ���Ԫ�ؾͷ���true
A, B�ַ����в���ȵ������ط�, ��Ҫ�鿴���ǽ������Ƿ���ȼ���
'''


class Solution:
    def buddyStrings(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        if s == goal:
            cnt = set()
            for c in s:
                if c in cnt:  # ���ظ�Ԫ��
                    return True
                cnt.add(c)
            return False
        diff1 = []  # ��¼��ͬ�ַ�
        diff2 = []
        cnt = 0  # ��¼��ͬ�ַ�����
        for i in range(len(s)):
            if s[i] != goal[i]:
                diff1.append(s[i])
                diff2.append(goal[i])
                cnt += 1
        # ��ͬ�ַ�Ϊ2�����ҽ��������
        if cnt == 2 and diff1[0] == diff2[1] and diff1[1] == diff2[0]:
            return True
        return False
