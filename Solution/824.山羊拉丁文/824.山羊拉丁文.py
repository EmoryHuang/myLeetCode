'''
Descroption: LeetCode 824. ɽ��������
Author: EmoryHuang
Date: 2021-09-18 19:04:30
Method:
����ÿ�����ʣ����������
'''


class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        words = sentence.split(' ')
        for i, word in enumerate(words):
            if word[0] not in 'aeiouAEIOU':
                words[i] = word[1:] + word[0]
            words[i] += 'ma' + 'a' * (i + 1)
        return ' '.join(words)
