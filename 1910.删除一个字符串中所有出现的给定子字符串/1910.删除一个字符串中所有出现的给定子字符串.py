'''
Descroption: LeetCode 1910. ɾ��һ���ַ��������г��ֵĸ������ַ���
Author: EmoryHuang
Date: 2021-07-22 18:48:07
����˼·:
�����ַ�����part���ֵ�λ�ã��滻Ϊ��
'''


class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while part in s:
            s = s.replace(part, '', 1)
        return s
