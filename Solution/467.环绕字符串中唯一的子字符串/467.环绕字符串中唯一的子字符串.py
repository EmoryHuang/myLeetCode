'''
Descroption: LeetCode 467. �����ַ�����Ψһ�����ַ���
Author: EmoryHuang
Date: 2022-05-25 09:11:47
Method:
��̬�滮
dp[i] ��ʾ�� i ��β���Ӵ��������
������ص���ֻ��Ҫ�������һ������Ϊ�����������п��ܵ����ַ���
������˵������ p����ά�������������Ӵ�����
�����ǰ�ַ�����һ���ַ��� s ����������ô�Ե�ǰ�ַ���β������Ⱦʹ�ǰ���ۼӣ���������µĿ�ʼ��
'''


class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        n = len(p)
        if n < 1: return 0
        # dp[i] ��ʾ�� i ��β���Ӵ��������
        # ������ص���ֻ��Ҫ�������һ������Ϊ�����������п��ܵ����ַ���
        dp = [0] * 26
        # ά�������������Ӵ�����
        max_len = 0
        for i in range(n):
            # �ж��Ƿ���ѭ���Ӵ���
            if i > 0 and (ord(p[i]) - ord(p[i - 1])) % 26 == 1:
                max_len += 1
            else:
                max_len = 1
            dp[ord(p[i]) - ord('a')] = max(dp[ord(p[i]) - ord('a')], max_len)
        return sum(dp)
