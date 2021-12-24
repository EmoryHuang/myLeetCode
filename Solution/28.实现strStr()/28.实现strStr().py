'''
Descroption: LeetCode 28. ʵ�� strStr()
Author: EmoryHuang
Date: 2021-12-24 10:28:16
Method:
�ַ�����ϣ
���ģʽ���Ĺ�ϣֵ������ı���ÿ������Ϊģʽ�����ȵ��Ӵ��Ĺ�ϣֵ���ֱ���ģʽ���Ĺ�ϣֵ�Ƚ�
'''

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

        B = 2
        n, m = len(haystack), len(needle)

        # ���� needle �� hash ֵ
        needle_hash = 0
        for i in range(m):
            needle_hash = needle_hash * B + ord(needle[i])

        # ���� haystack �� hash ֵ
        h, p = [0] * (n + 1), [0] * (n + 1)
        p[0] = 1
        for i in range(n):
            h[i + 1] = h[i] * B + ord(haystack[i])
            p[i + 1] = p[i] * B

        # �����Ӵ��� hash ֵ
        for i in range(1, n - m + 2):
            j = i + m - 1
            sub_hash = h[j] - h[i - 1] * p[j - i + 1]
            if sub_hash == needle_hash:
                if haystack[i - 1:j] == needle:
                    return i - 1
        return -1
