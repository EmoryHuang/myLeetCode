'''
Descroption: LeetCode 1790. ��ִ��һ���ַ��������ܷ�ʹ�����ַ������
Author: EmoryHuang
Date: 2021-08-05 20:05:03
Method:
���⣬��¼��Ӧλ�ò���ͬ��Ԫ�ظ���
'''


class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        if s1 == s2: return True
        if Counter(s1) != Counter(s2):
            return False
        cnt = 0
        for i in range(len(s1)):
            if s1[i] != s2[i]:
                cnt += 1
        return cnt == 2