'''
Descroption: LeetCode 424. �滻�����ظ��ַ�
Author: EmoryHuang
Date: 2021-07-31 14:55:12
Method:
�������� + ��ϣ��
ʹ�ù�ϣ���¼�ַ����ֵĴ�����ά���ַ������ִ�������ֵ maxn
���ų� maxn ����ͬ�ַ��󣬻������������д��� k ����ͬ���ַ�������˵�����
'''


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        l, r = 0, 0
        n = len(s)
        hash = [0] * 26
        maxn = 0
        while r < n:
            # ��¼�ַ����ֵĴ���
            hash[ord(s[r]) - ord('A')] += 1
            # �ҵ��ַ����ִ�������ֵ
            # ��������ֻ����򲻱�
            maxn = max(maxn, hash[ord(s[r]) - ord('A')])
            # ���ų� maxn ����ͬ�ַ������д��� k ����ͬ���ַ�
            if r - l + 1 - maxn > k:
                # ��Ϊ������˵�Ҫ���ƣ����Ҫ��ȥ
                hash[ord(s[l]) - ord('A')] -= 1
                l += 1
            r += 1
        return r - l
