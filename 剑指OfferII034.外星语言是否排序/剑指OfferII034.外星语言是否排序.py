'''
Descroption: ��ָ Offer II 034. ���������Ƿ�����
Author: EmoryHuang
Date: 2021-08-13 20:22:59
Method:
���������ֵ�������
'''


class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        return words == sorted(words, key=lambda x: [order.index(x) for x in x])
