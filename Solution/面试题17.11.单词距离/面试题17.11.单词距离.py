'''
Descroption: ������ 17.11. ���ʾ���
Author: EmoryHuang
Date: 2022-05-27 08:48:24
Method:
һ�α��� + ˫ָ��
��¼���ʳ��ֵ�λ�ã�ȡ��̾���
'''


class Solution:
    def findClosest(self, words: List[str], word1: str, word2: str) -> int:
        ans = len(words)
        index1, index2 = -1, -1
        for i, word in enumerate(words):
            if word == word1:
                index1 = i
            elif word == word2:
                index2 = i
            if index1 >= 0 and index2 >= 0:
                ans = min(ans, abs(index1 - index2))
        return ans