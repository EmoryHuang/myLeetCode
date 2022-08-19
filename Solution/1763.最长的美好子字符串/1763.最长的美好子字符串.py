'''
Descroption: LeetCode 1763. ����������ַ���
Author: EmoryHuang
Date: 2022-02-01 18:06:25
Method:
����
���ĳ���ַ��ڵ�ǰ�ַ�����û������Ӧ�Ĵ�д��Сд�ַ�����ô��ֻ��������߻������ұ�
���ظõ���߻��ұ߸��������ַ���
'''


class Solution:
    def longestNiceSubstring(self, s: str) -> str:
        if len(s) < 2:
            return ''
        for i, c in enumerate(s):
            if c.upper() not in s or c.lower() not in s:
                return max(self.longestNiceSubstring(s[:i]),
                           self.longestNiceSubstring(s[i + 1:]),
                           key=len)
        return s
