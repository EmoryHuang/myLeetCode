'''
Descroption: LeetCode 299. ��������Ϸ
Author: EmoryHuang
Date: 2021-07-30 13:36:23
Method:
ʹ��һ����ϣ��洢�����Ƿ����
��guess�е������ǹ�ţ���� hash ��һ
��secret�е������ǹ�ţ���� hash ��һ

�����ǰλ��Ϊ������˵��һ��������secret��δƥ����ַ�
�����ǰλ��Ϊ������˵��һ��������guess��δƥ����ַ�
'''


class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        a, b = 0, 0
        hash = [0] * 10
        for i in range((len(secret))):
            if secret[i] == guess[i]:
                a += 1
            else:
                # �����ǰλ��Ϊ������˵��һ��������secret��δƥ����ַ�
                if hash[int(guess[i])] > 0:
                    b += 1
                # ��guess�е������ǹ�ţ���� hash ��һ
                hash[int(guess[i])] -= 1
                # �����ǰλ��Ϊ������˵��һ��������guess��δƥ����ַ�
                if hash[int(secret[i])] < 0:
                    b += 1
                # ��secret�е������ǹ�ţ���� hash ��һ
                hash[int(secret[i])] += 1
        return str(a) + 'A' + str(b) + 'B'
