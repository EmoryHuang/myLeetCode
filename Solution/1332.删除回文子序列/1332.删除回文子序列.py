'''
Descroption: LeetCode 1332. ɾ������������
Author: EmoryHuang
Date: 2022-01-22 15:11:09
Method:
ģ��
��Ϊֻ����a��b��������ֻ��Ҫɾ�� 2 �μ���ɾ�����е��ַ�
'''


class Solution:
    def removePalindromeSub(self, s: str) -> int:
        return 1 if s == s[::-1] else 2
