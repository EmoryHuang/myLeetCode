'''
Descroption: LeetCode 1758. ���ɽ���������ַ��������ٲ�����
Author: EmoryHuang
Date: 2021-08-15 12:40:43
Method:
�����ַ������жϵ�ǰ�ַ����� 0101...01 �Լ� 1010...10�Ĳ���
'''


class Solution:
    def minOperations(self, s: str) -> int:
        cnt1, cnt2 = 0, 0
        for i in range(len(s)):
            if s[i] == str(i % 2):
                # �жϵ�ǰ�ַ����� 0101...01�Ĳ���
                cnt1 += 1
            else:
                # �жϵ�ǰ�ַ����� 1010...10�Ĳ���
                cnt2 += 1
        return min(cnt1, cnt2)
